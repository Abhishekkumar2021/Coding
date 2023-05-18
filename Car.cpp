#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

class Car {
    // Write your constructor and printCarInfo method here.
    public:
    int noOfGear;
    string color;
    Car(int noOfGear, string color){
        this->noOfGear = noOfGear;
        this->color = color;    
    }
    void printCarInfo(){
        cout << "noOfGear: " << noOfGear << endl;
        cout << "color: " << color << endl;
    }
};


class RaceCar: public Car {
    // Write your constructor and printRaceCarInfo method here.
    public:
    int maxSpeed;
    RaceCar(int noOfGear, string color, int maxSpeed): Car(noOfGear, color){
        this->maxSpeed = maxSpeed;
    }
    void printInfo(){
        printCarInfo();
        cout << "maxSpeed: " << maxSpeed << endl;
    }

};


int main() {
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printInfo();
    return 0;
}