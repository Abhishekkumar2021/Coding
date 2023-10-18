#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->value = val;
        next = prev = NULL;
    }
};

class LRUCache{
    int cap;
    int curr;
    Node* head; // LRU
    Node* tail; // MRU
    unordered_map<int, Node*> cache;

    public:
    LRUCache(int cap){
        this->cap = cap;
        curr = 0;
        head = tail = NULL;
    }

    void add(Node* node){
        if(head == NULL){
            head = tail = node;
            node->next = head;
            node->prev = tail;
        }else{
            head->prev = node;
            tail->next = node;
            node->next = head;
            node->prev = tail;
        }
    }

    void remove(Node* node){
        if(head == tail){
            head = tail = NULL;
            return;
        }

        if(head == node){
            head = head->next;
            head->prev = tail;
            tail->next = head;
            return;
        }

        if(tail == node){
            tail = tail->prev;
            tail->next = head;
            head->next = tail;
            return;
        }

        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key){
        if(cache.find(key) != cache.end()){
            // Now we have accesed it so we have to make it most recently used
            // First remove it out
            remove(cache[key]);
            // And then add it 
            add(cache[key]);
            return cache[key]->value;
        } 
        return -1;
    }

    void put(int key, int val){
        // First check if it is already there
        if(cache.find(key) != cache.end()){
            // Now we have accesed it so we have to make it most recently used
            // First remove it out
            remove(cache[key]);
            // And then add it 
            add(cache[key]);
            cache[key]->value = val;
        } 
        else{
            // If current size is equal to capacity then first we have to remove the LRU and then insert it
            if(curr == cap){
                cache.erase(head->key);
                remove(head);
                curr--;
            }
            Node* newNode = new Node(key, val);
            cache[key] = newNode;
            add(newNode);
            curr++;
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    LRUCache l(n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int key;
            cin >> key;
            cout << l.get(key) << "\n";
        }else{
            int key, val;
            cin >> key >> val;
            l.put(key, val);
        }
    }
    return 0;
}
