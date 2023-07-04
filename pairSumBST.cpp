#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isExist(BinaryTreeNode<int> *root, int target, int cnt){
    if(target == 0 && cnt == 2) return true;
    if(root == NULL || cnt == 2) return false;

    if(root->data <= target){
        // Include current node
        if(root->data <= target/2) return isExist(root->right, target - root->data, cnt+1);
        else return isExist(root->left, target - root->data, cnt+1);

        // Exclude current node
        return isExist(root->left, target, cnt) || isExist(root->right, target, cnt);
    }
    
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
}