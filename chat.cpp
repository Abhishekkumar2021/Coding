#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("Input.txt");
    ofstream fout("Result.md");

    char ch;
    string query = "";
    while(fin.get(ch)){
        if(ch == '"') query += "\\\"";
        else query += ch;
    }

    string command = "sgpt \" Give the result in proper markdown form with language specific syntax highlighting and enough semantics of markdown. The query is - " + query + "\" > Result.md";
    system(command.c_str());
    return 0;  
}

