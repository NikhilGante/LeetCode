#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}

    int key, val;
    Node* prev, *next;
};

class LRUCache {
    Node* head = nullptr, *tail = nullptr;
    int max_size = 0;
    unordered_map<int, Node*> mp; // Key, cur

    public:
        LRUCache(int capacity) {
            max_size = capacity;
            mp.reserve(3000);
        }
        ~LRUCache(){
            while(head){
                Node* next = head->next;
                delete head;
                head = next;
            }
        }
        
        int get(int key) {
            if(mp.find(key) == mp.end())    return -1;  // Key not found
            else{   // If already in list, move to front (head) and return val
                Node* node = mp[key];
                if(node != head){

                    if(node == tail)    tail = node->prev;
                    // Connect prev and next
                    if(node->prev)    node->prev->next = node->next;    // Node is not head
                    if(node->next)    node->next->prev = node->prev;    // Node is not tail

                    // Update head
                    head->prev = node;
                    node->next = head;
                    node->prev = nullptr;
                    head = node;
                }
                return node->val;
            }
        }
        
        void put(int key, int value) {
            if(mp.find(key) == mp.end()){   // Insert at head of list if not in map already
                if(mp.size() >= max_size){   // Evict tail if capacity reached
                    mp.erase(tail->key);
                    if(tail == head)    head = nullptr;
                    Node* prev_tail = tail;
                    tail = tail->prev;
                    delete prev_tail;
                    if(tail)    tail->next = nullptr;
                }


                Node* new_node = new Node(key, value);
                if(head){
                    head->prev = new_node;
                    new_node->next = head;
                }
                else    tail = new_node;
                head = new_node;
                mp[key] = new_node;
            }
            else{   // If already in list, move to front (head) and update val
                Node* node = mp[key];
                node->val = value;
                if(node != head){

                    if(node == tail)    tail = node->prev;
                    // Connect prev and next
                    if(node->prev)    node->prev->next = node->next;    // Node is not head
                    if(node->next)    node->next->prev = node->prev;    // Node is not tail

                    // Update head
                    head->prev = node;
                    node->next = head;
                    node->prev = nullptr;
                    head = node;
                }
            }
        }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */