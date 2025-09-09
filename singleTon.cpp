#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class singleton{
    private:
    static singleton* instance;
    singleton(){
        cout<<"singleton object is created"<<endl;
    }
    public:
    static singleton* getInstance(){
        if(instance==nullptr){
            instance=new singleton();
        }
        return instance;
    }
};

singleton* singleton::instance=nullptr;

int main(){
    singleton* s1=singleton::getInstance();
    singleton* s2=singleton::getInstance();

    cout<<(s1==s2)<<endl;
}