//
// Created by tabarak on 7/5/2025.
//

#ifndef EXPIRABLEPRODUCT_H
#define EXPIRABLEPRODUCT_H
#include "Product.h"
#include <bits/stdc++.h>
using namespace std;

// Now we add the expiration behavior.
class ExpirableProduct : public Product {
  time_t expiryTime_;

public:

  ExpirableProduct(const string& name, double price, int stock, time_t expiry);
  void validateExpiry() const override;

};



#endif //EXPIRABLEPRODUCT_H
