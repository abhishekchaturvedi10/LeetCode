class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(int key, int val) {
        Node* newNode = new Node(key, val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* resNode = cache[key];
            int res = resNode->val;
            deleteNode(resNode); 
            addNode(key, res); 
            cache[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            deleteNode(node);
            cache.erase(key);
        }
        if (cache.size() == cap) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            deleteNode(lru);
        }
        addNode(key, value);
        cache[key] = head->next;
    }
};