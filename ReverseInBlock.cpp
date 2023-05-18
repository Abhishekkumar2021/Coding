/*
You are given a Singly Linked List of integers and an integer array 'B' of size 'N'. Each
element in the array 'B' represents a block size. Modify the linked list by reversing the
nodes in each block whose sizes are given by the array 'B'.
Note:
1. If you encounter a situation when 'B [i]' is greater than the number
of remaining nodes in the list, then simply reverse the remaining nodes
as a block and ignore all the block sizes from 'BC i]' .
2. All block sizes are contiguous i.e. suppose that block 'B[i]' ends at
a node cur, then the block 'B[i+l]' starts from the node just after the
node cur.
Example
Linked list: 1->2->3->4->5
Array B: 3 3 5
Output : 3->2->1->5->4
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    int i = 0;
    while(curr!=NULL && i<n){
        count = 0;
        prev = NULL;
        while(curr!=NULL && count<b[i]){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        i++;
    }
    return prev;

}