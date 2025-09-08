// Liskov Substitution Principle Example
#include <iostream>
using namespace std;

class Shape {
public:
    int height;
    int width;
    Shape(int h, int w) {
        height = h;
        width = w;
    }
    virtual void area() = 0; 
};

class Rectangle : public Shape {
public:
    Rectangle(int h, int w) : Shape(h, w) {}
    void area() override {
        cout << "Rectangle area is " << height * width << endl;
    }
};

class Square : public Shape {
public:
    Square(int size) : Shape(size, size) {}
    void area() override {
        cout << "Square area is " << height * width << endl;
    }
};

int main() {
    Shape* s1 = new Rectangle(10, 5);
    Shape* s2 = new Square(7);

    // Both objects can be used interchangeably via base class pointer
    s1->area();
    s2->area();

    delete s1;
    delete s2;

    return 0;
}
