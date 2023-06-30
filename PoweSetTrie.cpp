#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* zero;
    Node* one;

    Node(){
        zero = NULL;
        one = NULL;
    }
};


class Trie{
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void helper(Node* curr, int idx, int n){
        if(idx == n){
            return;
        }

        curr->zero = new Node();
        curr->one = new Node();

        helper(curr->zero, idx+1, n);
        helper(curr->one, idx+1, n);
    }

    void makePowerSet(int n){
        helper(root, 0, n);
    }

    void f(Node* curr, vector<int> &arr, int idx, vector<int> &sub, vector<vector<int>> &ans){
        if(idx == arr.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(arr[idx]);
        f(curr->one, arr, idx+1, sub, ans);
        sub.pop_back();
        f(curr->zero, arr, idx+1, sub, ans); 
    }

    vector<vector<int>> powerSet(vector<int> &arr){
        vector<vector<int>> ans;
        vector<int> sub;
        f(root, arr, 0, sub, ans);
    }
};