#ifndef CART_H
#define CART_H
#include<bits/stdc++.h>
#include <memory>
#include "../products/Product.h"
using namespace std;

struct CartItem {
    shared_ptr<Product> product;
    int                      quantity;
};

class Cart {
  vector<CartItem> items_;
  public:
    void add(shared_ptr<Product> product, int qty);
    const vector<CartItem>& items() const;
    bool empty() const;

};



#endif //CART_H
