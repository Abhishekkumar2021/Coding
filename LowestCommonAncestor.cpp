#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node* right;
};

// Method 1 : O(N^2)
bool search(Node* root, Node* x){
    if(root==NULL) return false;
    if(root == x) return true;
    return search(root->left, x) || search(root->right, x);
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL) return root;
    if(root == p || root == q) return root;
    bool a = search(root->left, p);
    bool b = search(root->right, q);
    if(a && !b) return lowestCommonAncestor(root->left, p, q);
    if(!a && b) return lowestCommonAncestor(root->right, p, q);
    return root;
}

// Method 2: O(N)
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL) return root;
    if(root == p || root == q) return root;
    Node* a =  lowestCommonAncestor(root->left, p, q);
    Node* b =  lowestCommonAncestor(root->right, p, q);
    if(a != NULL && b != NULL) return root;
    if(a != NULL) return a;
    return b;
}


// Method 3: O(N) space and time
void build(Node* root, map<Node*, Node*> &mp, Node* par){
    if(root==NULL) return;
    mp[root] = par;
    build(root->left, mp, root);
    build(root->right, mp, root);
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    map<Node*, Node*> mp;
    build(root, mp, NULL);
    set<Node*> s;
    while(p != NULL){
        s.insert(p);
        p = mp[p];
    }
    while(q != NULL){
       if(s.find(q) != s.end()) return q;
       q = mp[q];
    }
    return NULL;
}