
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <bits/stdc++.h>
#include "../customer/Customer.h"
#include "../cart/Cart.h"
using namespace std;

class EmptyCartException : public runtime_error {
public:
    EmptyCartException(const string& msg) : runtime_error(msg) {}
};

void checkout (Customer& customer, Cart& cart);

#endif //CHECKOUT_H
