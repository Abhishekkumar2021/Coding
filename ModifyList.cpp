#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class result{
    public:
    ListNode* mid;
    ListNode* prev;
    result(){
        prev = mid = NULL;
    }
    result(ListNode* prev, ListNode* mid){
        this->prev = prev;
        this->mid = mid;
    }
};

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

result mid(ListNode* head){
    ListNode* fast = head, *slow = head, *prev = NULL;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    return result(prev, slow);
}

ListNode* subtract(ListNode* A) {
    result res = mid(A);
    res.prev->next = NULL;
    ListNode* second = reverse(res.mid);
    ListNode* temp = A; 
    ListNode* s = second;
    while(temp != NULL && s != NULL){
        temp->val = s->val - temp->val;
        temp = temp->next;
        s = s->next;
    }
    second = reverse(second);
    res.prev->next = second;
    return A;
}