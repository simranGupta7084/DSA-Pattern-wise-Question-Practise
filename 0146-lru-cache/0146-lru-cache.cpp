class LRUCache {
public:

    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node just after head
    void add(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // This key is recently used
        remove(node);
        add(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Move to front
            remove(node);
            add(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        add(node);

        // Cache is full
        if (mp.size() > capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};