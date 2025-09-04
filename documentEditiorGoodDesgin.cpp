#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class documentElement{
    public:
    virtual string render()=0;
};

class textElement:public documentElement{
    public:
    string text;
    textElement(string txt){
        text=txt;
    }
    string render() override{
        return text;
    }
};

class imageElemrnt: public documentElement{
    public:
    string imagePath;
    imageElemrnt(string txt){
        imagePath=txt;
    }
    string render() override{
        return imagePath;
    }
};

class addNewLine:public documentElement{
    public:
    string render() override{
        return "\n";   
    }
};

class addTabSpace:public documentElement{
    public:
    string render() override{
        return "\t";   
    }
};

class document{
    public:
    vector<documentElement*> element;
    void addElement(documentElement* txt){
        element.push_back(txt);
    }

    string render(){
        string res;
        for(auto it: element){
            res+=it->render();
        }
        return res;
    }
};

class parsistance{
    public:
    virtual void save(string data)=0;
};

class saveTofile:public parsistance{
    public:
    void save(string data) override{
        ofstream file("temp1.txt");
        if(file.is_open()){
            file<<data;
            file.close();
            cout<<"success\n";
        }
        else{
            cout<<"something went wrong\n";
        }
    }
};

class saveToDb: public parsistance{
    public:
    void save(string data) override{
        cout<<"Pretend saving to DB: "<<data<<"\n";
    }
};

class documentEditior{
    public:
    document* d1;
    parsistance* storage;
    string renderString;

    documentEditior(document* d1, parsistance* s){
        this->d1=d1;
        storage=s;
    }

    void addText(string txt){
        d1->addElement(new textElement(txt));
    }

    void addImage(string path){
        d1->addElement(new imageElemrnt(path));
    }

    void addnewLine(){
        d1->addElement(new addNewLine());
    }

    void addtabSpace(){
        d1->addElement(new addTabSpace());
    }

    string renderDocument(){
        if(renderString.empty()){
            renderString=d1->render();
        }
        return renderString;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
};

int main(){
    document d;
    saveTofile fileSaver;
    documentEditior editor(&d, &fileSaver);

    editor.addText("Hello, World!");
    editor.addnewLine();
    editor.addText("This is a test document.");
    editor.addnewLine();
    editor.addtabSpace();
    editor.addText("Indented line after tab.");
    editor.addnewLine();
    editor.addImage("picture.jpg");

    cout<<editor.renderDocument()<<endl;
    editor.saveDocument();

    return 0;
}
