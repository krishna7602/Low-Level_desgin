#include <iostream>
using namespace std;

// --- Product Interface ---
class burgerPreparation {
public:
    virtual void prepare() = 0;
    virtual ~burgerPreparation() {}
};

// --- Concrete Products ---
class simpleBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Simple burger is preparing..." << endl;
    }
};

class standardBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Standard burger is preparing..." << endl;
    }
};

class premiumBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Premium burger is preparing..." << endl;
    }
};

// --- Factory ---
class burgerFactory {
public:
    burgerPreparation* createBurger(const string& type) {
        if (type == "basic") {
            return new simpleBurger();
        } 
        else if (type == "standard") {
            return new standardBurger();
        } 
        else if (type == "premium") {
            return new premiumBurger();
        } 
        else {
            cout << "This burger type is not in the menu!" << endl;
            return nullptr;
        }
    }
};

// --- Client ---
int main() {
    burgerFactory factory;

    burgerPreparation* burger1 = factory.createBurger("basic");
    if (burger1) {
        burger1->prepare();
        delete burger1;
    }

    cout << "------------------" << endl;

    burgerPreparation* burger2 = factory.createBurger("premium");
    if (burger2) {
        burger2->prepare();
        delete burger2;
    }

    cout << "------------------" << endl;

    burgerPreparation* burger3 = factory.createBurger("xyz"); // invalid
    if (burger3) {
        burger3->prepare();
        delete burger3;
    }

    return 0;
}
