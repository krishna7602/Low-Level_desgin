// Single Responsibility Principle Example

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BreadBaker {
public:
    string bakerName;
    BreadBaker(string name) {
        bakerName = name;
    }
    void Bake() {
        cout << bakerName << " is baking fresh bread..." << endl;
    }
};

class InventoryManagement {
public:
    void Manage() {
        cout << "Inventory is being checked and restocked as needed." << endl;
    }
};

class CustomerService {
public:
    void HandleCustomer() {
        cout << "Assisting customers with their queries and orders." << endl;
    }
};

class AllDayCal {
public:
    void CalculateRevenue() {
        cout << "Calculating total sales and revenue for the day." << endl;
    }
};

int main() {
    
    BreadBaker baker("John");
    InventoryManagement inventory;
    CustomerService service;
    AllDayCal calculator;

    baker.Bake();
    inventory.Manage();
    service.HandleCustomer();
    calculator.CalculateRevenue();

    return 0;
}
