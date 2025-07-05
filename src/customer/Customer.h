
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <bits/stdc++.h>
using namespace std;

// Exception when balance is not enough
using BalanceException = runtime_error;

class Customer {
    string name_;
    double balance_;
public:
    Customer(const string& name, double balance);
    double getBalance() const;
    void   charge(double amount);
};



#endif //CUSTOMER_H
