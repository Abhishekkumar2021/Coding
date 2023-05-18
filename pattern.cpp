#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int row = 1;
    while(row<=n){
        // First spaces
        int space = n - row;
        while(space>0){
            cout<<" ";
            space--;
        }
        // Decreasing numbers
        int number = row;
        while(number>0){
            cout<<number;
            number--;
        }

        // Increasing numbers
        number = 2;
        while(number<=row){
            cout<<number;
            number++;
        }
        cout<<endl;
        row++;
    }
}