struct Node {
    Node(int k = 0, int v = 0):
        key(k), value(v){}
        
    int key;
    int value;
    shared_ptr<Node> pre;
    shared_ptr<Node> next;
};

bool operator == (const Node& node1, const Node& node2){
    return node1.key == node2.key && node1.value == node2.value;
}

namespace std {
    template<>
    struct hash<Node> {
        size_t operator()(const Node& node) const noexcept {
            return std::hash<int>()(node.key << 16 | node.value);
        }
    };
}

class LinkedList {
public:
    LinkedList(){
        head = make_shared<Node>();
        tail = make_shared<Node>();
        head->next = tail;
        head->pre = nullptr;
        tail->pre = head;
        tail->next = nullptr;
    }

    shared_ptr<Node> add(int key, int val){
        // print();
        shared_ptr<Node> node = make_shared<Node>(key, val);
        shared_ptr<Node> next = head->next;
        
        head->next = node;
        node->next = next;
        next->pre  = node;
        node->pre = head;
        return node;
    }

    int pop(){
        shared_ptr<Node> cur = tail->pre;
        if(cur == head)
            return -1;
        shared_ptr<Node> pre = cur->pre;
        pre->next = tail;
        tail->pre = pre;
        return cur->key;
    }

    void moveToHead(shared_ptr<Node>& node){
        shared_ptr<Node> pre = node->pre;
        shared_ptr<Node> next = node->next;
        pre->next = next;
        next->pre = pre;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }

private:
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if(cache_.count(key)){
           auto cur = cache_[key];
           list.moveToHead(cur);
           return cur->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        shared_ptr<Node> cur = {};
        if(cache_.count(key)){
            cur = cache_[key];
            cur->value = value;
        }else{
            if(cache_.size() == cap_){
                int key = list.pop();   
                cache_.erase(key);
            }
            cur = list.add(key, value);
            cache_[key] = cur;
        }
        list.moveToHead(cur);
    }

private:
    int cap_ = 0;
    unordered_map<int, shared_ptr<Node>> cache_ = {};
    LinkedList list = {};
};
