#include <iostream>
using namespace std;

class Car {
public:
    string model;
    int topSpeed;
    string wheelsBrand;

    Car(string model, int topSpeed) {
        this->model = model;
        this->topSpeed = topSpeed;
        this->wheelsBrand = "mrf";
    }

    void carInfo() {
        cout << "Car model: " << model 
             << ", Top speed: " << topSpeed 
             << ", Wheels: " << wheelsBrand << endl;
    }
};

class Mannualcar : public Car {
public:
    int gear;
    int curgear;

    Mannualcar(int gear, int curgear, string model, int topSpeed)
        : Car(model, topSpeed) {
        this->gear = gear;
        this->curgear = curgear;
    }

    void manualCarInfo() {
        cout << "Manual car with " << gear 
             << " gears, currently in gear " << curgear << endl;
    }
};

class Ecar : public Car {
public:
    int batteryPercentage;

    Ecar(int batteryPercentage, string model, int topSpeed)
        : Car(model, topSpeed) {
        this->batteryPercentage = batteryPercentage;
    }

    void ecarInfo() {
        cout << "Electric car with battery " << batteryPercentage << "%" << endl;
    }
};

int main() {
    Mannualcar m1(6, 2, "Maruti", 180);
    m1.carInfo();    
    m1.manualCarInfo(); 
    cout << "Top speed: " << m1.topSpeed << endl; 

    cout << "-----------------" << endl;

    Ecar e1(85, "Tesla", 250);
    e1.carInfo();     
    e1.ecarInfo();      

    return 0;
}
