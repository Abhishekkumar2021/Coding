//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/

struct Node *new_insert(struct Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
    return temp;
    if(head->next == NULL)
    {
        head->next = temp;
        return head;
    }
    Node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

struct Node *reverse_list(struct Node *head)
{
    if(head == NULL || head->next == NULL)
    return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;
    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        struct Node *head =NULL;
        struct Node *temp = NULL;
        if(odd == NULL || odd->next == NULL || odd->next->next == NULL)
        return;
        struct Node *curr = odd;
        while(curr != NULL && curr->next != NULL)
        {
            int d;
            d = curr->next->data;
            curr->next= curr->next->next;
            curr = curr->next;
            head = new_insert(head, d);
        }
        head = reverse_list(head);
        curr = odd;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = head;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends