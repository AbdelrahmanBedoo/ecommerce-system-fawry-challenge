#include "Product.h"
#include <string>

// I included this just in case I forgot to include some necessary library.
#include <bits/stdc++.h>

using namespace std;

Product::Product(const string& name, double price, int stock)
    : name_(name), price_(price), stock_(stock) {}

const string& Product::getName() const { return name_;}
double Product::getPrice() const { return price_; }
int Product::getStock() const { return stock_; }

void Product::validateStock(int qty) const {
    if (qty <= 0 || qty > stock_)
        throw StockException("There is no sufficient stock for: " + name_);
}

void Product::reduceStock(int qty) {
    validateStock(qty);
    stock_ -= qty;
}

void Product::validateExpiry() const {
    // This is by defalut not-expirable.
}