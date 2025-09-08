#include <iostream>
#include <string>
using namespace std;

// Abstraction: Payment Interface
class IPayment {
public:
    virtual void pay(double amount) = 0;
    virtual ~IPayment() = default;
};

// Low-level module: Paytm
class Paytm : public IPayment {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " via Paytm\n";
    }
};

// Low-level module: GPay
class GPay : public IPayment {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " via Google Pay\n";
    }
};

// High-level module: Payment Processor (depends on abstraction, not details)
class PaymentProcessor {
    IPayment* paymentMethod; // abstraction
public:
    PaymentProcessor(IPayment* method) : paymentMethod(method) {}

    void process(double amount) {
        paymentMethod->pay(amount);
    }
};

int main() {
    Paytm paytm;
    GPay gpay;

    PaymentProcessor processor1(&paytm);
    processor1.process(500);

    PaymentProcessor processor2(&gpay);
    processor2.process(1000);

    return 0;
}
