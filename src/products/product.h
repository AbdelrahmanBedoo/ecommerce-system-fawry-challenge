#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdexcept>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

// These are exceptions in case of expiration or a stock problem.
using StockException     = runtime_error;
using ExpiredException   = runtime_error;

// This class is the base product
class Product {
protected:
    string name_;
    double price_;
    int    stock_;

public:

    Product(const string& name, double price, int stock);
    virtual ~Product() = default;

    // These are just getter functions.
    const string& getName() const;
    double getPrice() const;
    int getStock() const;


    // Functions to validate the stock and change it
    virtual void validateStock(int qty) const;
    virtual void reduceStock(int qty);

    // Expiry check
    virtual void validateExpiry() const;
};


#endif //PRODUCT_H
