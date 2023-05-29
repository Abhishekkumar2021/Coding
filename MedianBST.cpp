#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void nodeAtIndex(TreeNode<int> *root, int index, int &count, int &ans)
{
    if (!root)
        return;

    nodeAtIndex(root->left, index, count, ans);
    count++;
    if (count == index)
    {
        ans = root->data;
        return;
    }
    nodeAtIndex(root->right, index, count, ans);
}

int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int medianBST(TreeNode<int> *root)
{
    int n = countNodes(root);
    int count = 0, ans = -1;
    nodeAtIndex(root, n / 2 + 1, count, ans);
    if(n%2==0)
    {
        int count2 = 0, ans2 = -1;
        nodeAtIndex(root, n / 2, count2, ans2);
        return (ans+ans2)/2;
    }
    return ans;
}