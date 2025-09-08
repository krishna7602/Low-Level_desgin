#include <iostream>
using namespace std;

// --- Product Interface ---
class burgerPreparation {
public:
    virtual void prepare() = 0;
    virtual ~burgerPreparation() {}
};

// --- Concrete Products ---
class basicBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Basic burger is prepared" << endl;
    }
};

class standardBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Standard burger is prepared" << endl;
    }
};

class premiumBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Premium burger is prepared" << endl;
    }
};

class wheatBasicBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Wheat basic burger is prepared" << endl;
    }
};

class wheatStandardBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Wheat standard burger is prepared" << endl;
    }
};

class wheatPremiumBurger : public burgerPreparation {
public:
    void prepare() override {
        cout << "Wheat premium burger is prepared" << endl;
    }
};

// --- Factory Interface ---
class burgerFactory {
public:
    virtual burgerPreparation* createBurger(string &type) = 0;
    virtual ~burgerFactory() {}
};

// --- Concrete Factories ---
class kingBurgarFactory : public burgerFactory {
public:
    burgerPreparation* createBurger(string &type) override {
        if (type == "basic") return new basicBurger();
        else if (type == "standard") return new standardBurger();
        else if (type == "premium") return new premiumBurger();
        else {
            cout << "This type is not available in King Burger." << endl;
            return nullptr;
        }
    }
};

class singhBurgerFactory : public burgerFactory {
public:
    burgerPreparation* createBurger(string &type) override {
        if (type == "basic") return new wheatBasicBurger();
        else if (type == "standard") return new wheatStandardBurger();
        else if (type == "premium") return new wheatPremiumBurger();
        else {
            cout << "This type is not available in Singh Burger." << endl;
            return nullptr;
        }
    }
};

// --- Client ---
int main() {
    string type;

    // Using King Burger Factory
    kingBurgarFactory kingFactory;
    type = "basic";
    burgerPreparation* b1 = kingFactory.createBurger(type);
    if (b1) {
        b1->prepare();
        delete b1;
    }

    cout << "-------------------" << endl;

    // Using Singh Burger Factory
    singhBurgerFactory singhFactory;
    type = "premium";
    burgerPreparation* b2 = singhFactory.createBurger(type);
    if (b2) {
        b2->prepare();
        delete b2;
    }

    cout << "-------------------" << endl;

    // Invalid case
    type = "xyz";
    burgerPreparation* b3 = kingFactory.createBurger(type);
    if (b3) {
        b3->prepare();
        delete b3;
    }

    return 0;
}
