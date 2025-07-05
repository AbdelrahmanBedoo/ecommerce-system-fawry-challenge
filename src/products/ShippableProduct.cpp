#include "ShippableProduct.h"
#include <bits/stdc++.h>

using namespace std;

ShippableProduct::ShippableProduct(const string& name, double price, int stock, double unitWeight)
    : Product(name, price, stock), unitWeight_(unitWeight) {}


string ShippableProduct::getName() const {
    return name_;
}

double ShippableProduct::getWeight(int qty) const {
    return unitWeight_ * qty;
}