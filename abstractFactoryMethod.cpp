#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ------------------ Burger ------------------
class burger {
public:
    virtual void prepare() = 0;
    virtual ~burger() = default;
};

class basicBurger : public burger {
public:
    void prepare() override {
        cout << "basic burger is preparing" << endl;
    }
};

class standardBurger : public burger {
public:
    void prepare() override {
        cout << "standard burger is preparing" << endl;
    }
};

class premiumBurger : public burger {
public:
    void prepare() override {
        cout << "premium burger is preparing" << endl;
    }
};

class wheatBasicBurger : public burger {
public:
    void prepare() override {
        cout << "wheat basic burger is preparing" << endl;
    }
};

class wheatStandardBurger : public burger {
public:
    void prepare() override {
        cout << "wheat standard burger is prepared" << endl;
    }
};

class wheatPremiumBurger : public burger {
public:
    void prepare() override {
        cout << "wheat premium burger is prepared" << endl;
    }
};

// ------------------ Garlic Bread ------------------
class garlicBread {
public:
    virtual void prepare() = 0;
    virtual ~garlicBread() = default;
};

class basicGarlicBread : public garlicBread {
public:
    void prepare() override {
        cout << "basic garlic bread is preparing" << endl;
    }
};

class standardGarlicBread : public garlicBread {
public:
    void prepare() override {
        cout << "standard garlic bread is preparing" << endl;
    }
};

class premiumGarlicBread : public garlicBread {
public:
    void prepare() override {
        cout << "premium garlic bread is preparing" << endl;
    }
};

// ------------------ Abstract Factory ------------------
class restaurantFactory {
public:
    virtual burger* createBurger(const string &type) = 0;
    virtual garlicBread* createGarlicBread(const string &type) = 0;
    virtual ~restaurantFactory() = default;
};

// ------------------ Concrete Factories ------------------
class kingBurgerFactory : public restaurantFactory {
public:
    burger* createBurger(const string &type) override {
        if (type == "basic") return new basicBurger();
        else if (type == "standard") return new standardBurger();
        else if (type == "premium") return new premiumBurger();
        else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }

    garlicBread* createGarlicBread(const string &type) override {
        if (type == "basic") return new basicGarlicBread();
        else if (type == "standard") return new standardGarlicBread();
        else if (type == "premium") return new premiumGarlicBread();
        else {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};

class singhBurgerFactory : public restaurantFactory {
public:
    burger* createBurger(const string &type) override {
        if (type == "basic") return new wheatBasicBurger();
        else if (type == "standard") return new wheatStandardBurger();
        else if (type == "premium") return new wheatPremiumBurger();
        else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }

    garlicBread* createGarlicBread(const string &type) override {
        if (type == "basic") return new basicGarlicBread(); // reuse
        else if (type == "standard") return new standardGarlicBread();
        else if (type == "premium") return new premiumGarlicBread();
        else {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};

// ------------------ Client ------------------
int main() {
    // Client chooses restaurant (Abstract Factory)
    restaurantFactory* factory = new kingBurgerFactory();

    // Order food
    burger* b = factory->createBurger("standard");
    garlicBread* g = factory->createGarlicBread("premium");

    // Prepare food
    if (b) b->prepare();
    if (g) g->prepare();

    // Cleanup
    delete b;
    delete g;
    delete factory;

    cout << "-------------------" << endl;

    // Another restaurant
    restaurantFactory* factory2 = new singhBurgerFactory();
    burger* b2 = factory2->createBurger("basic");
    garlicBread* g2 = factory2->createGarlicBread("standard");

    if (b2) b2->prepare();
    if (g2) g2->prepare();

    delete b2;
    delete g2;
    delete factory2;

    return 0;
}
