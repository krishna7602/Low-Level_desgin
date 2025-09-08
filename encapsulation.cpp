#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car{
    int curGear;
    int curSpeed;

    public:
    string model;
    int topSpeed;

    void setCurgear(int n){
        if(n>1 && n<=6) {
            cout<<"the gear is set into,"<<n<<endl;
            curGear=n;
        }
    }

    void getCurgear(){
        cout<<"current gear is "<<curGear<<endl;
    }

    void setCurspeed(int n){
        cout<<"current speed is"<<n<<endl;
        curSpeed=n;
    }

    Car(string model, int topSpeed){
        this->model=model;
        this->topSpeed=topSpeed;
    }

    void run(){
        cout<<" car is running"<<curSpeed<<endl;
    }
};

int main(){
    Car c1("maruti",200);

    c1.setCurgear(3);
    c1.getCurgear();
    c1.setCurspeed(100);
    c1.run();
}