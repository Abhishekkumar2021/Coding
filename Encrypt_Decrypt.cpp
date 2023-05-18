/*
Write an algorithm to encrypt and  decrypt a string which contains characters from whole ASCII set.

Encryption Algorithm:
1. Take the first character of the string and add 1 to its ASCII value.
2. Take the second character of the string and subtract 1 from its ASCII value.
3. Repeat the above steps for all the characters of the string.
4. Print the encrypted string.

Decryption Algorithm:
1. Take the first character of the encrypted string and subtract 1 from its ASCII value.
2. Take the second character of the encrypted string and add 1 to its ASCII value.
3. Repeat the above steps for all the characters of the encrypted string.
4. Print the decrypted string.
*/

#include <bits/stdc++.h> 
using namespace std;

string encode(string secretInformation) {
	// Write your code here.
	int n = secretInformation.length();
    for(int i=0;i<n;i++){
        if(i%2==0){
            secretInformation[i] = secretInformation[i]+1;
        }
        else{
            secretInformation[i] = secretInformation[i]-1;
        }
    }
    return secretInformation;

}

string decode(string encodedInformation) {
	// Write your code here.
    int n = encodedInformation.length();
    for(int i=0;i<n;i++){
        if(i%2==0){
            encodedInformation[i] = encodedInformation[i]-1;
        }
        else{
            encodedInformation[i] = encodedInformation[i]+1;
        }
    }
    return encodedInformation;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        string secretInformation;
        getline(cin,secretInformation);
        string encodedInformation = encode(secretInformation);
        cout<<encodedInformation<<endl;
        string decodedInformation = decode(encodedInformation);
        cout<<decodedInformation<<endl;
    }
    return 0;
}

