#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> child;
    int prefix;
    int end;
    Node()
    {
        child.resize(26, NULL);
        prefix = 0;
        end = 0;
    }
};

class Trie
{

public:
    Node *root;
    int count;

    Trie()
    {
        root = new Node();
        count = 0;
    }

    void insert(string &word)
    {
        int n = word.size();
        Node *curr = root;
        for (int i = 0; i < n; i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] != NULL)
                curr = curr->child[ind];
            else
            {
                curr->child[ind] = new Node();
                curr = curr->child[ind];
            }
            curr->prefix++;
        }
        curr->end++;
        count++;
    }

    int countWordsEqualTo(string &word)
    {
        int n = word.size();
        Node *curr = root;
        for (int i = 0; i < n; i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] == NULL)
                return 0;
            curr = curr->child[ind];
        }
        return curr->end;
    }

    int countWordsStartingWith(string &word)
    {
        int n = word.size();
        Node *curr = root;
        for (int i = 0; i < n; i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] == NULL)
                return 0;
            curr = curr->child[ind];
        }
        return curr->prefix;
    }

    void erase(string &word)
    {
        // Write your code here.
        int n = word.size();
        Node *curr = root;
        for (int i = 0; i < n; i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] == NULL)
                return;
            curr = curr->child[ind];
            curr->prefix--;
        }
        curr->end--;
        count--;
    }
};
