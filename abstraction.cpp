#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    virtual void startEngine()=0;
    virtual void stopEngine()=0;
};

class Alto:public Car{
    public:
    string model;
    int gear;
    int topSpeed;
    Alto(string model,int gear, int topSpeed){
        this->model=model;
        this->gear=gear;
        this->topSpeed=topSpeed;
    }
    void startEngine(){
        cout<<"started engine!! now you can go";
    }

    void stopEngine(){
        cout<<"stop the engine";
    }
};

int main(){
    Alto c1("maruti",6,200);

    c1.startEngine();
    c1.stopEngine();

}