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
public:
    LRUCache(const int cap): capacity(cap)
    {
        this->cache.clear();

        this->left = new Node(0, 0);
        this->right = new Node(0, 0);

        this->left->next = right;
        this->right->prev = left;
    }

    int get(int key)
    {
        if (cache.count(key))
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if (cache.size() > capacity)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node *left, *right;

    void insert(Node* node)
    {
        Node* prev = right->prev;
        Node* nxt = right;

        nxt->prev = node;
        prev->next = node;

        node->prev = prev;
        node->next = nxt;
    }

    void remove(Node* node)
    {
        Node* nxt = node->next;
        Node* prev = node->prev;

        prev->next = nxt;
        nxt->prev = prev;
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
    cout << "Getting 1: " << lru.get(1) << endl;
    cout << "Putting 3,3" << endl;
    lru.put(3, 3);
    cout << "Getting 2: " << lru.get(2) << endl;
    cout << "Putting 4,4" << endl;
    lru.put(4, 4);
    cout << "Getting 1: " << lru.get(1) << endl;
    cout << "Getting 3: " << lru.get(3) << endl;
    cout << "Getting 4: " << lru.get(4) << endl;
    return 0;
}
