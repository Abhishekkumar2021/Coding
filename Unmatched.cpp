#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "akansha";
    string y = "abhishek";

    // use of find_first_not_of is to find the first character of s that is not in y
    int IndexOffirstCharacterOfSThatIsNotInY = s.find_first_not_of(y);
    cout << IndexOffirstCharacterOfSThatIsNotInY << endl; // ans = 3 as 'n' is the first character of s that is not in y
}