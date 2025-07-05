#ifndef ISHIPPABLE_H
#define ISHIPPABLE_H

#include <string>
#include <bits/stdc++.h>

using namespace std;

// This is just an interface for shipping.
class IShippable {
  public:
    virtual ~IShippable() = default;
    virtual string getName() const = 0;
    // This is the total weight in kg for given quantity
    virtual double getWeight(int qty) const = 0;
};


#endif //ISHIPPABLE_H
