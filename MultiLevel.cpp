#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

// Create the classes here
class GrandFather{
    public:
    string grandfatherName;
    GrandFather(string x){
        grandfatherName = x;
    }
};

class Father: public GrandFather{
    public:
    string fatherName;
    Father(string x, string y): GrandFather(x){
        fatherName = y;
    }
};

class Son : public Father{
    public:
    string sonName;
    Son(string x, string y, string z): Father(x, y){
        sonName = z;
    }
    void printName(){
        cout << "sonname:  " << sonName << endl;
        cout<< "fathername:  "<< fatherName << endl;
        cout<< "grandfather:  "<< grandfatherName <<endl;
    }
};

int main() {

    //Write your code here
    Son s("Suresh", "Ramesh", "Saurabh");
    s.printName();

    return 0;
}