#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IVegetarianMenu {
public:
    virtual vector<string> getVegetarianItems() = 0;
    virtual ~IVegetarianMenu() = default;
};


class INonVegetarianMenu {
public:
    virtual vector<string> getNonVegetarianItems() = 0;
    virtual ~INonVegetarianMenu() = default;
};


class IDrinkMenu {
public:
    virtual vector<string> getDrinkItems() = 0;
    virtual ~IDrinkMenu() = default;
};


class VegetarianMenu : public IVegetarianMenu {
public:
    vector<string> getVegetarianItems() override {
        return {"Vegetable Curry", "Paneer Tikka", "Salad"};
    }
};


class NonVegetarianMenu : public INonVegetarianMenu {
public:
    vector<string> getNonVegetarianItems() override {
        return {"Chicken Curry", "Fish Fry", "Mutton Biryani"};
    }
};

class DrinkMenu : public IDrinkMenu {
public:
    vector<string> getDrinkItems() override {
        return {"Water", "Soda", "Juice"};
    }
};

void printMenu(const vector<string>& items, const string& title) {
    cout << title << ":\n";
    for (const auto& item : items) {
        cout << "- " << item << endl;
    }
    cout << endl;
}

int main() {
    VegetarianMenu vegMenu;
    NonVegetarianMenu nonVegMenu;
    DrinkMenu drinkMenu;

    printMenu(vegMenu.getVegetarianItems(), "Vegetarian Menu");
    printMenu(nonVegMenu.getNonVegetarianItems(), "Non-Vegetarian Menu");
    printMenu(drinkMenu.getDrinkItems(), "Drink Menu");

    return 0;
}
