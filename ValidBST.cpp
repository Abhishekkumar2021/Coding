#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

bool helper(Node* root, int mini, int maxi){
    if(root == NULL) return true;
    if(root->data <= mini || root->data >= maxi) return false;
    return helper(root->left, mini, root->data) && helper(root->right, root->data, maxi);
}

bool isvalid(Node* root){
    return helper(root, INT_MIN, INT_MAX);
}