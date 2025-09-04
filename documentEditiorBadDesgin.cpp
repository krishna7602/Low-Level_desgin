#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    public:
    vector<string> documentElement;
    string renderText;

    DocumentEditor(string txt){
        documentElement.push_back(txt);
    }

    void addText(string txt){
        documentElement.push_back(txt);
    }

    void addImage(string imagePath){
        documentElement.push_back(imagePath);
    }

    string renderDocument(){
        if(renderText.empty()){
            string res;
            for(auto it:documentElement){
                if(it.length()>4 && (it.substr(it.size()-4)==".jpg" || it.substr(it.size()-4)==".png")){
                    res+="Image path:"+it;
                }
                else{
                    res+=it+"/n";
                }
            }
            renderText=res;
        }
        return renderText;
    }

    void saveFile(){
        ofstream file("temp.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"writing in file is succefull";
        }
        else{
            cout<<"some thing is went wrong";
        }
    }
};

int main() {
    
    DocumentEditor editor("Hello, this is the start of my document.");

    editor.addText("This is another line of text.");
    editor.addText("Here comes an image...");


    editor.addImage("picture.jpg");
    editor.addImage("diagram.png");
    editor.addImage("profile.png");

    cout << "Rendered Document:" << endl;
    cout << editor.renderDocument() << endl;

    // Save to file
    editor.saveFile();

    return 0;
}
