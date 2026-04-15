// https://leetcode.com/problems/lru-cache/description/

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:

    int capacity;
    
    // key -> Node*
    unordered_map<int, Node*> cache;

    // dummy nodes
    // so when we insert a new node, it will be between left and right
    Node* left;
    Node* right;


    LRUCache(int capacity) {
        this->capacity = capacity;

        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    // When we get a value, we need to put it to end of the doubly linked list
    // to mark it as most recently used, then we can finally return its value assuming it exists
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    // if key already exists, remove the node and add back the new node with the given value
    // Because this is outside of the if statement, we create the node regardless if it exists or not without issue
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            Node* oldNode = cache[key];
            remove(oldNode);
        }

        Node* node = new Node(key, value);
        cache[key] = node; 
        add(node);

        // handle capacity exceeded
        if(cache.size() > capacity)
        {
            Node* deleteNode = left->next;
            remove(deleteNode);
            cache.erase(deleteNode->key);
        }
        
    }

private:
    // for removing node from doubly linked list
    // for ex, if  we have 1 <-> 2 <-> 3
    // 1 needs to point to 3, and 3 points to 1 assuming we want to remove 2
    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // for adding node to doubly linked list
    // add to the end of the list since we can define that as msot recently used
    void add(Node* node)
    {

        Node* prevEnd = right->prev;

        prevEnd->next = node;
        node->prev = prevEnd;
        
        node->next = right;
        right->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
