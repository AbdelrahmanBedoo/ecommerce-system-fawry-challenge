#include <bits/stdc++.h>
#include "ExpirableShippable.h"

using namespace std;

ExpirableShippable::ExpirableShippable(const string& name, double price, int stock, time_t expiry, double unitWeight)
    : ExpirableProduct(name, price, stock, expiry), unitWeight_(unitWeight) {}

string ExpirableShippable::getName() const {
    return name_;
}

double ExpirableShippable::getWeight(int qty) const {
    return unitWeight_ * qty;
}
