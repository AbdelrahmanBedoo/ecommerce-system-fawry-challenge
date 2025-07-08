# E-Commerce System - C++ Implementation

This is a project for a production-ready e-commerce system built with C++ and uses comprehensive OOP design, featuring product management, cart operations, checkout processing, and shipping services.

##  Project Overview

This implementation was developed for the **Fawry Rise Journey Full Stack Development Internship Challenge**. It demonstrates advanced C++ programming concepts including inheritance, polymorphism, smart pointers, exception handling, and modular architecture.

##  Features

### Core Functionality
- **Product Management**: Define products with name, price, and quantity
- **Product Types**: Support for expirable and shippable products
- **Cart Operations**: Add products with quantity validation
- **Checkout Process**: Complete order processing with receipt generation
- **Shipping Service**: Automatic shipping calculation and notification
- **Customer Management**: Balance tracking and payment processing

### Product Categories
- **Expirable Products**: Products with expiration dates (e.g., Cheese, Biscuits)
- **Shippable Products**: Products requiring shipping with weight information 
- **Expirable & Shippable**: Products with both expiration and shipping requirements
- **Simple Products**: Basic products without special requirements (e.g., Mobile scratch cards)

### Error Handling
- **Stock Validation**: Prevents adding more items than available
- **Expiration Checking**: Validates product expiration dates
- **Balance Verification**: Ensures sufficient customer balance
- **Cart Validation**: Prevents checkout with empty cart
- **User-Friendly Error Messages**: Clear, descriptive error notifications

##  Architecture

### Directory Structure
```
src/
├── interfaces/
│   └── IShippable.h          # Shipping interface
├── products/
│   ├── Product.h             # Base product class
│   ├── Product.cpp
│   ├── ExpirableProduct.h    # Expirable product mixin
│   ├── ExpirableProduct.cpp
│   ├── ShippableProduct.h    # Shippable product mixin
│   ├── ShippableProduct.cpp
│   ├── ExpirableShippable.h  # Combined expirable & shippable
│   ├── ExpirableShippable.cpp
│   ├── SimpleProduct.h       # Basic product
│   └── SimpleProduct.cpp
├── customer/
│   ├── Customer.h            # Customer management
│   └── Customer.cpp
├── cart/
│   ├── Cart.h               # Shopping cart
│   └── Cart.cpp
├── shipping/
│   ├── ShippingService.h    # Shipping calculations
│   └── ShippingService.cpp
├── order/
│   ├── Checkout.h           # Checkout process
│   └── Checkout.cpp
├── utils/
│   └── DateUtils.h          # Date utility functions
└── main.cpp                 # Test scenarios and examples
```

### Class Hierarchy
```
Product (Base Class)
├── ExpirableProduct
├── ShippableProduct
├── ExpirableShippable
└── SimpleProduct

IShippable (Interface)
├── ShippableProduct
└── ExpirableShippable

Customer
Cart
ShippingService
Checkout
```

##  Setup & Installation

### Prerequisites
- **C++17** or higher
- **CMake** 3.16 or higher
- **Compiler**: GCC, Clang, or MSVC

### Build Instructions

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd ecommerce-system-fawry-challenge
   ```

2. **Create build directory**
   ```bash
   mkdir build
   cd build
   ```

3. **Configure with CMake**
   ```bash
   cmake ..
   ```

4. **Build the project**
   ```bash
   cmake --build .
   ```

5. **Run the application**
   ```bash
   ./ecommerce_system_fawry_challenge
   ```


### Basic Product Creation
```cpp
#include "products/ExpirableShippable.h"
#include "products/ShippableProduct.h"
#include "products/SimpleProduct.h"
#include "utils/DateUtils.h"

// Create different product types
auto cheese = make_shared<ExpirableShippable>("Cheese", 100.0, 5, makeExpiry(2025,7,10), 0.2);
auto tv = make_shared<ShippableProduct>("TV", 2000.0, 2, 15.0);
auto scratchCard = make_shared<SimpleProduct>("ScratchCard", 50.0, 10);
```

### Customer and Cart Operations
```cpp
#include "customer/Customer.h"
#include "cart/Cart.h"

// Create customer
Customer customer("Alice", 5000.0);

// Add products to cart
Cart cart;
cart.add(cheese, 2);
cart.add(tv, 1);
cart.add(scratchCard, 2);
```

### Checkout Process
```cpp
#include "order/Checkout.h"

// Process checkout
try {
    checkout(customer, cart);
} catch (const std::exception& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
}
```

##  Testing

The system includes comprehensive test scenarios covering all corner cases:

### Test Scenarios
1. **Normal Scenario**: Basic checkout with multiple product types
2. **Zero/Negative Quantities**: Validation of invalid quantities
3. **Expired Products**: Handling of expired items
4. **Boundary Weight Shipping**: Testing shipping cost calculations
5. **Empty Cart**: Prevention of empty cart checkout
6. **Insufficient Balance**: Customer balance validation
7. **Out of Stock**: Stock availability checking
8. **Exact Balance**: Edge case with exact payment amount


##  License

This project is developed for the Fawry Rise Journey Internship Challenge.

