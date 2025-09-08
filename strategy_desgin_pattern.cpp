#include <iostream>
using namespace std;

// --- Strategy Interface ---
class PaymentMethod {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentMethod() {}
};

// --- Concrete Strategies ---
class GPay : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Payment of " << amount << " successfully done using GPay.\n";
    }
};

class Paytm : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Payment of " << amount << " successfully done using Paytm.\n";
    }
};

class CreditCard : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Payment of " << amount << " successfully done using Credit Card.\n";
    }
};

// --- Context Class ---
class Payment {
private:
    PaymentMethod* method;   

public:
    Payment(PaymentMethod* m){
        method=m;
    }

    void processPayment(int amount) {
        if (method) {
            method->pay(amount);   
        } else {
            cout << "No payment method selected.\n";
        }
    }

 
    void setPaymentMethod(PaymentMethod* m) {
        method = m;
    }
};


int main() {

    GPay gpay;
    Paytm paytm;
    CreditCard credit;

    
    Payment payment(&gpay);
    payment.processPayment(500);

    cout << "-------------------" << endl;

    payment.setPaymentMethod(&paytm);
    payment.processPayment(1000);

    cout << "-------------------" << endl;

    payment.setPaymentMethod(&credit);
    payment.processPayment(2000);

    return 0;
}
