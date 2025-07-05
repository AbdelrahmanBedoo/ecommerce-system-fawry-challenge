#ifndef EXPIRABLESHIPPABLE_H
#define EXPIRABLESHIPPABLE_H

#include <bits/stdc++.h>
#include <string>
#include "ExpirableProduct.h"
#include "../interfaces/IShippable.h"

using namespace std;


class ExpirableShippable : public ExpirableProduct, public IShippable {
    double unitWeight_;

  public:
    ExpirableShippable(const string& name, double price, int stock, time_t expiry, double unitWeight);

    string getName() const override;
    double getWeight(int qty) const override;
};




#endif //EXPIRABLESHIPPABLE_H
