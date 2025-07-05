
#include "Cart.h"
#include <memory>
#include <bits/stdc++.h>

using namespace std;

void Cart::add(shared_ptr<Product> product, int qty) {
    product->validateExpiry();
    product->validateStock(qty);
    items_.push_back({product, qty});
}

const vector<CartItem>& Cart::items() const {
    return items_;
}

bool Cart::empty() const {
    return items_.empty();
}