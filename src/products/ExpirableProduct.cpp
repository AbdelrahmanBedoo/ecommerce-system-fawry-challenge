    #include <ctime>
    #include "ExpirableProduct.h"
    #include <bits/stdc++.h>
    using namespace std;

    ExpirableProduct::ExpirableProduct(const string& name, double price, int stock, time_t expiry)
        : Product(name, price, stock), expiryTime_(expiry) {

        }

    void ExpirableProduct::validateExpiry() const {
        if (time(nullptr) > expiryTime_)
            throw ExpiredException("Sorry but this product is already expired: " + name_);
    }