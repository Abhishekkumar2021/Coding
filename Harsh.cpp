#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    while(!cin.eof()){
        string line;
        getline(cin, line);
        // If string contains img then output image
        bool img = false;
        bool doc = false;
        if(line.find("img") != string::npos){
            img = true;
        }else if(line.find("doc") != string::npos){
            doc = true;
        }
        
        if(img && doc){
            cout << "presentation\n";
        }else if(img){
            cout << "image\n";
        }else if(doc){
            cout << "document\n";
        }
        else cout << "other\n";
    }
    
    return 0;
}