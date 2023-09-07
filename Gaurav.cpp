#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    vector<Node*> child;
    int end;
    int prefix;

    Node(){
        child.resize(26, NULL);
        end = 0;
        prefix = 0;
    }
};

class Trie{
    Node* root;
    int count;
    public:
    Trie(){
        root = new Node();
    }

    // Insertion
    void insert(string s){
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] != NULL){
                curr = curr->child[idx];
            }else{
                curr->child[idx] = new Node();
                curr = curr->child[idx];
            }
            curr->prefix++; 
        }
        // setting that string is ended here
        curr->end++;
        curr->prefix++;
        count++;
    }

    bool search(string s){
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL) return false;
            curr = curr->child[idx];
        }
        return curr->end;
    }

    void lazyDelete(string s){
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL) return;
            curr = curr->child[idx];
            curr->prefix--;
        }
        curr->end--;
        curr->prefix--;
        count--;
    }

    void exhaustiveDelete(string s){
        stack<Node*> st;
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL) return;
            st.push(curr);
            curr = curr->child[idx];
            curr->prefix--;
        }
        curr->end--;
        curr->prefix--;
        for(int i=0; i<26; i++){
            if(curr->child[i] != NULL) return;
        }

        int i = s.size()-1;
        while(i>=0 && st.top()->end == 0){
            Node* second = st.top();
            st.pop();
            second->child[i] = NULL;
            i--;
        }
        count--;
    }

    int prefixCount(string s){
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL) return 0;
            curr = curr->child[idx];
        }
        return curr->prefix;
    }

    int countComplete(string s){
        int n = s.size();
        Node* curr = root;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(curr->child[idx] == NULL) return 0;
            curr = curr->child[idx];
        }
        return curr->end;
    }

    int size(){
        return count;
    }

    string longestCommonPrefix(){
        string ans = "";
        Node* curr = root;

    }
};

int main(){
    Trie t;
    t.insert("abc");
    t.insert("abgl");
    t.insert("cdf");
    t.insert("abcd");
    t.insert("lmn");

    cout<<t.search("abc")<<endl;
    cout<<t.search("abgl")<<endl;
    cout<<t.search("cdf")<<endl;

    t.lazyDelete("abc");
    cout<<t.search("abc")<<endl;

    t.exhaustiveDelete("abgl");
    cout<<t.search("abgl")<<endl;
}

