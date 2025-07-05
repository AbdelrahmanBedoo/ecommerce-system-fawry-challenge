#ifndef SIMPLEPRODUCT_H
#define SIMPLEPRODUCT_H
#include "product.h"
#include <bits/stdc++.h>
using namespace std;


// This is for the simple product that requires no shipping and is not expirable.

class SimpleProduct : public Product {
public:
    SimpleProduct(const string& name, double price, int stock);
};




#endif //SIMPLEPRODUCT_H
