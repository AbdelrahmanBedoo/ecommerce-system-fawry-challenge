#include "Customer.h"
#include <bits/stdc++.h>
using namespace std;

Customer::Customer(const string& name, double balance)
    : name_(name), balance_(balance) {}

double Customer::getBalance() const {
    return balance_;
}

void Customer::charge(double amount) {
    if (amount > balance_)
        throw BalanceException("There is no suffiecient amount in your balance.");
    balance_ -= amount;
}