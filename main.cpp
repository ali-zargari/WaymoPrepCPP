#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr)
    {

    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left; // lru
    Node* right;// mru

public:
    LRUCache(const int cap)
    {
        capacity = cap;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;

    }

    int get(int key)
    {
        if (cache.contains(key))
        {
            //remove node, place it where most recently used is.

            Node* node = cache[key];

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next=nullptr;
            node->prev=nullptr;

            Node* temp = right->prev;

            right->prev = node;
            node->next = right;
            temp->next = node;
            node->prev = temp;

            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.contains(key))
        {
            cache[key]->val = value;

            Node* node = cache[key];

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next=nullptr;
            node->prev=nullptr;

            Node* temp = right->prev;

            right->prev = node;
            node->next = right;
            temp->next = node;
            node->prev = temp;
        } else
        {
            Node* nn = new Node(key, value);
            cache[key] = nn;

            Node* temp = right->prev;
            right->prev = nn;
            nn->next = right;
            temp->next = nn;
            nn->prev = temp;


            if (cache.size() > capacity)
            {
                //delete LRU

                Node* temp = left->next;
                int tempkey = temp->key;
                cache.erase(tempkey);

                left->next = temp->next;
                left->next->prev = temp->prev;
                temp->prev = nullptr;
                temp->next = nullptr;

            }

        }
    }
};

// --- Main function with test cases (modified slightly for clarity) ---
int main()
{
LRUCache lru = LRUCache(2);
cout << "Putting 1,1" << endl;
lru.put(1, 1);
cout << "Putting 2,2" << endl;
lru.put(2, 2);
cout << "Getting 1: " << lru.get(1) << " (Expected: 1)" << endl;
cout << "Putting 3,3" << endl;
lru.put(3, 3);
cout << "Getting 2: " << lru.get(2) << " (Expected: -1)" << endl;
cout << "Putting 4,4" << endl;
lru.put(4, 4);
cout << "Getting 1: " << lru.get(1) << " (Expected: -1)" << endl;
cout << "Getting 3: " << lru.get(3) << " (Expected: 3)" << endl;
cout << "Getting 4: " << lru.get(4) << " (Expected: 4)" << endl;
return 0;
}
