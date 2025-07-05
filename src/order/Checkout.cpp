#include "../shipping/ShippingService.h"
#include "../interfaces/IShippable.h"
#include "Checkout.h"
#include <bits/stdc++.h>
using namespace std;

void checkout(Customer& customer, Cart& cart) {
    if (cart.empty()) throw EmptyCartException("Cart is empty");

    double subtotal = 0;
    double shippingFee = 0;
    double totalWeight = 0;


    // The first step is that to validate and then accumalate
    for (const auto& c : cart.items()) {
        c.product->validateExpiry();
        c.product->validateStock(c.quantity);
        subtotal += c.product->getPrice() * c.quantity;
    }

    // Then compute the shipping bees based on weight brackets (10 per 0.5kg)
    for (const auto& c : cart.items()) {
        auto* shp = dynamic_cast<IShippable*>(c.product.get());
        if (shp) {
            totalWeight += shp->getWeight(c.quantity);
        }
    }
    shippingFee = ceil(totalWeight / 0.5) * 10.0;

    double totalDue = subtotal + shippingFee;


    // Balance check
    customer.charge(totalDue);

    // Deduct stock
    for (const auto& c : cart.items()) c.product->reduceStock(c.quantity);

    ShippingService::ship(cart.items());

    // Finally we print the receipt.
    std::cout << "** Checkout receipt **\n";
    for (const auto& c : cart.items()) {
        std::cout << c.quantity << "x "
                  << c.product->getName() << " @ "
                  << c.product->getPrice() << " each\n";
    }
    std::cout << "----------------------\n"
              << "Subtotal " << subtotal << "\n"
              << "Shipping "<< shippingFee<<"\n"
              << "Amount "  << totalDue   << "\n"
              << "Remaining balance "<<customer.getBalance()<<"\n";
}