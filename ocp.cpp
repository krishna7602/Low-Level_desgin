// Open/Closed Principle Example

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class PaymentMethod {
public:
    virtual void pay(double amount) = 0; 
    virtual ~PaymentMethod() {} 
};


class Paytm : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Payment of Rs. " << amount << " made via Paytm." << endl;
    }
};


class GPay : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Payment of Rs. " << amount << " made via Google Pay." << endl;
    }
};


class CreditCard : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Payment of Rs. " << amount << " made via Credit Card." << endl;
    }
};

int main() {
    
    vector<PaymentMethod*> payments;

    payments.push_back(new Paytm());
    payments.push_back(new GPay());
    payments.push_back(new CreditCard());

    
    for (auto method : payments) {
        method->pay(500.00); // Rs. 500 payment with each method
    }

    return 0;
}
