#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* left;
    Node* right;

    Node(string s){
        data = s;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<string> &arr, int i, int j){
    if(i>j) return NULL;
    int mid = (i+j)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildTree(arr, i, mid-1);
    root->right = buildTree(arr, mid+1, j);
    return root;
}

void helper(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    helper(root->left);
    helper(root->right);
}

bool comp(string a, string b){
    if(stoi(a) > stoi(b)) return true;
    return false;
}

void preorderTraverse(string s){
    vector<string> arr;
    int i = 0;
    int n = s.size();
    while(i<n){
        string first = "";
        first.push_back(s[i]);
        arr.push_back(first);
        i++;
        if(i<n){
            string second = "";
            second.push_back(s[i]);
            i++;
            if(i < n){
                second.push_back(s[i]);
                i++;
            }
            arr.push_back(second);
        }
    }
    // reverse order sorting
    sort(arr.begin(), arr.end(), comp);
    Node* root = buildTree(arr, 0, arr.size()-1);
    helper(root);
}

int main(){
    string s;
    cin>>s;
    preorderTraverse(s);
}