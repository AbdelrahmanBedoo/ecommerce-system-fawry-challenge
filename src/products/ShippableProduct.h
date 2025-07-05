#ifndef SHIPPABLEPRODUCT_H
#define SHIPPABLEPRODUCT_H
#include "Product.h"
#include "../interfaces/IShippable.h"
#include <bits/stdc++.h>
using namespace std;


// This is a mixin for the weight per unit
class ShippableProduct : public Product, public IShippable {
    double unitWeight_;
public:
    ShippableProduct(const string& name, double price, int stock, double unitWeight);
    string getName() const override;
    double getWeight(int qty) const override;
};



#endif //SHIPPABLEPRODUCT_H
