#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string generatePassword(int length) {
    string password = "";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int randomChar = rand() % 62;
        if (randomChar < 26)
            password += 'a' + randomChar;
        else if (randomChar < 52)
            password += 'A' + (randomChar - 26);
        else
            password += '0' + (randomChar - 52);
    }
    return password;
}

int main() {
    int length;
    cout << "Enter the length of the password: ";
    cin >> length;
    cout << "Your password is: " << generatePassword(length) << endl;
    return 0;
}