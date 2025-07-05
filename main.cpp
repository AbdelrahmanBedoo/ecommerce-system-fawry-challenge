#include "products/ExpirableShippable.h"
#include "products/ShippableProduct.h"
#include "products/SimpleProduct.h"
#include "customer/Customer.h"
#include "cart/Cart.h"
#include "shipping/ShippingService.h"
#include "order/Checkout.h"
#include "utils/DateUtils.h"
#include <iostream>
#include <ctime>

using namespace std;

void testNormalScenario() {
    cout << "\n=== TEST 1: Normal Scenario ===" << endl;
    try {
        using std::make_shared;
        auto cheese   = make_shared<ExpirableShippable>("Cheese", 100.0, 5, makeExpiry(2025,7,10), 0.2);
        auto biscuits = make_shared<ExpirableShippable>("Biscuits",150.0,3, makeExpiry(2025,7,8), 0.7);
        auto tv       = make_shared<ShippableProduct>("TV",2000.0,2,15.0);
        auto scratch  = make_shared<SimpleProduct>("ScratchCard",50.0,10);

        Customer ahmed("Ahmed", 5000.0);
        Cart cart;
        cart.add(cheese, 2);
        cart.add(biscuits,1);
        cart.add(tv, 1);
        cart.add(scratch,2);

        checkout(ahmed, cart);
    }
    catch(const std::exception& ex) {
        cerr << "ERROR: " << ex.what() << endl;
    }
}

void testZeroOrNegativeQuantities() {
    cout << "\n=== TEST 2: Zero or Negative Quantities ===" << endl;

    // Test zero quantity
    try {
        auto cheese = make_shared<ExpirableShippable>("Cheese", 100.0, 5, makeExpiry(2025,7,10), 0.2);
        Customer Mohammed("Mohammed", 1000.0);
        Cart cart;

        cout << "Testing zero quantity" << endl;
        cart.add(cheese, 0);
        checkout(Mohammed, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }

    // Test negative quantity
    try {
        auto cheese = make_shared<ExpirableShippable>("Cheese", 100.0, 5, makeExpiry(2025,7,10), 0.2);
        Customer Mohammed("Mohammed", 1000.0);
        Cart cart;

        cout << "Testing negative quantity:" << endl;
        cart.add(cheese, -1);
        checkout(Mohammed, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }
}

void testExpiredProduct() {
    cout << "\n=== TEST 3: Expired Product ===" << endl;
    try {
        // Create a product that expires yesterday
        time_t yesterday = time(nullptr) - 86400; // 24 hours ago
        auto expiredCheese = make_shared<ExpirableShippable>("Expired Cheese", 100.0, 5, yesterday, 0.2);

        Customer Abdelrahman("Abdelrahman", 1000.0);
        Cart cart;
        cart.add(expiredCheese, 1);

        cout << "Attempting checkout with expired product:" << endl;
        checkout(Abdelrahman, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }
}

void testBoundaryWeightShipping() {
    cout << "\n=== TEST 4: Boundary Weight for Shipping ===" << endl;
    try {
        // Test exactly 0.5kg (should be 1 bracket = 10 shipping)
        auto lightItem = make_shared<ShippableProduct>("Light Item", 50.0, 10, 0.5);

        Customer Sara("Sara", 1000.0);
        Cart cart;
        cart.add(lightItem, 1);

        cout << "Testing exactly 0.5kg shipping:" << endl;
        checkout(Sara, cart);
    }
    catch(const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }

    try {
        // Test exactly 1.0kg (should be 2 brackets = 20 shipping)
        auto mediumItem = make_shared<ShippableProduct>("Medium Item", 100.0, 10, 1.0);

        Customer salma("Salma", 1000.0);
        Cart cart2;
        cart2.add(mediumItem, 1);

        cout << "Testing exactly 1.0kg shipping..." << endl;
        checkout(salma, cart2);
    }
    catch(const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }

    try {
        // Test 0.49kg (should be 1 bracket = 10 shipping)
        auto veryLightItem = make_shared<ShippableProduct>("Very Light Item", 30.0, 10, 0.49);

        Customer saad("Saad", 1000.0);
        Cart cart3;
        cart3.add(veryLightItem, 1);

        cout << "Testing 0.49kg shipping (should be 1 bracket)" << endl;
        checkout(saad, cart3);
    }
    catch(const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void testEmptyCart() {
    cout << "\n=== TEST 5: Empty Cart ===" << endl;
    try {
        Customer ahmed("Ahmed", 1000.0);
        Cart cart;

        cout << "Attempting checkout with empty cart:" << endl;
        checkout(alice, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }
}

void testInsufficientBalance() {
    cout << "\n=== TEST 6: Insufficient Balance ===" << endl;
    try {
        auto expensiveTV = make_shared<ShippableProduct>("Expensive TV", 5000.0, 1, 20.0);

        Customer verypoorCustomer("Poor Customer", 100.0);
        Cart cart;
        cart.add(expensiveTV, 1);

        cout << "Attempting checkout with insufficient balance..." << endl;
        checkout(verypoorCustomer, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }
}

void testOutOfStock() {
    cout << "\n=== TEST 7: Out of Stock ===" << endl;

    // Test 1: Immediate validation during cart.add()
    try {
        auto limitedItem = make_shared<SimpleProduct>("Limited Item", 50.0, 2);
        Customer alice("Alice", 1000.0);
        Cart cart;

        cout << "Test 7a: Immediate validation during cart.add()..." << endl;
        cart.add(limitedItem, 5); // Try to add 5 when only 2 available
        cout << "This line should not be reached if validation works correctly" << endl;
        checkout(alice, cart);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }

    // Test 2: Stock becomes insufficient during checkout (after other items reduce stock)
    try {
        auto item1 = make_shared<SimpleProduct>("Item 1", 50.0, 3);
        auto item2 = make_shared<SimpleProduct>("Item 2", 30.0, 1);
        Customer bob("Bob", 1000.0);
        Cart cart2;

        cout << "Test 7b: Stock validation during checkout..." << endl;
        cart2.add(item1, 2); // Add 2, and 1 in stock
        cart2.add(item2, 1); // Add 1, and 0 in stock

        // Now try to add more of item1, but stock was reduced during checkout
        cart2.add(item1, 2); // Try to add 2 more, but only 1 left

        checkout(bob, cart2);
    }
    catch(const std::exception& ex) {
        cout << "Expected error: " << ex.what() << endl;
    }
}

void testExactBalance() {
    cout << "\n=== TEST 8: Exact Balance ===" << endl;
    try {
        auto cheapItem = make_shared<SimpleProduct>("Cheap Item", 100.0, 5);

        Customer exactCustomer("Exact Customer", 100.0);
        Cart cart;
        cart.add(cheapItem, 1);

        cout << "Testing checkout with exact balance..." << endl;
        checkout(exactCustomer, cart);
        cout << "Remaining balance should be 0" << endl;
    }
    catch(const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

int main() {
    cout << "Testing corner Cases " << endl << endl << end;

    testNormalScenario();
    testZeroOrNegativeQuantities();
    testExpiredProduct();
    testBoundaryWeightShipping();
    testEmptyCart();
    testInsufficientBalance();
    testOutOfStock();
    testExactBalance();

    cout << "\n=== ALL TESTS COMPLETED ===" << endl;
    return 0;
}