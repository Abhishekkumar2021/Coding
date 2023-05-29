#include<bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

// BinaryTreeNode<int>* constructBst(vector<int>& levelOrder)
// {
//     // Write Your Code Here.
//     if(levelOrder.size()==0)
//         return NULL;
    
//     vector<int> left, right;
//     int root = levelOrder[0];
//     for(int i=1;i<levelOrder.size();i++)
//     {
//         if(levelOrder[i]<root)
//             left.push_back(levelOrder[i]);
//         else
//             right.push_back(levelOrder[i]);
//     }

//     BinaryTreeNode<int>* rootnode = new BinaryTreeNode<int>(root);
//     rootnode->left = constructBst(left);
//     rootnode->right = constructBst(right);
//     return rootnode;
// }

BinaryTreeNode<int>* construct(vector<int>& levelOrder, int start, int end)
{
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(levelOrder[mid]);
    root->left = construct(levelOrder, start, mid-1);
    root->right = construct(levelOrder, mid+1, end);
    return root;
}


BinaryTreeNode<int>* constructBst(vector<int>& levelOrder)
{
    // Write Your Code Here.
    sort(levelOrder.begin(), levelOrder.end());
    int start = 0, end = levelOrder.size()-1;
    return construct(levelOrder, start, end);     
}