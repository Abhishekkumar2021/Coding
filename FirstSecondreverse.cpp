#include <bits/stdc++.h>
using namespace std;
/**********************

    Following is the class structure of the Node class:



***********************/
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *prev = NULL, *curr = head, *furr = head;
    while (furr)
    {
        furr = furr->next;
        curr->next = prev;
        prev = curr;
        curr = furr;
    }
    return prev;
}

Node *add(Node *head1, Node *head2)
{
    int carry = 0;
    Node *prev;
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    while (head1 && head2)
    {
        int sum = head1->data + head2->data + carry;
        carry = sum / 10;
        head1->data = sum % 10;
        prev = head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1)
    {
        int sum = head1->data + carry;
        carry = sum / 10;
        head1->data = sum % 10;
        prev = head1;
        head1 = head1->next;
    }
    while (carry)
    {
        Node *t = new Node(carry % 10);
        carry = carry / 10;
        prev->next = t;
        prev = prev->next;
        t->next = NULL;
    }
    return head1;
}

Node *addFirstAndReversedSecondHalf(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head2 = slow->next;
    slow->next = NULL;

    Node *head1 = head;
    head2 = reverse(head2);

    head1 = add(head1, head2);

    return reverse(head1);
}