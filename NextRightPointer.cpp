#include<bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Tree need not to be complete
void connect(TreeLinkNode* root) {
    TreeLinkNode* head = root;

    while(head){
        TreeLinkNode* curr = head;
        TreeLinkNode* prev = NULL;
        head = NULL;
        while(curr){
            if(curr->left){
                if(prev) prev->next = curr->left;
                else head = curr->left;
                prev = curr->left;
            }
            if(curr->right){
                if(prev) prev->next = curr->right;
                else head = curr->right;
                prev = curr->right;
            }
            curr = curr->next;
        }
    }
}
