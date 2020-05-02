#include <functional>
#include <memory>
#include <unordered_map>

using std::shared_ptr;
using std::unordered_map;
using std::make_shared;

template<typename K, typename V>
struct BiNode {
    K key;
    V value;
    BiNode(int k, int v = 0):key(k), value(v){};
    shared_ptr<BiNode> pre;
    shared_ptr<BiNode> next;
};

template<typename K, typename V>
bool operator==(const BiNode<K, V>& node1, const BiNode<K, V>& node2){
    return node1.key == node2.key;
}

namespace std {

    template<typename K, typename V>
    struct hash<BiNode<K, V>> {
        size_t operator()(const BiNode<K, V>& node) const noexcept {
            return std::hash<size_t>()(node.key);
        }
    };
}



template<typename K, typename V>
class LRUList {
public:
    using NodeType = BiNode<K, V>;
    using PNodeType = shared_ptr<NodeType>;

    LinkedList(){
        head_ = make_shared<NodeType>();
        tail_ = make_shared<NodeType>();
        head_->next = tail_;
        tail_->pre = head_;
    }

    PNodeType add(K key, V value){
        PNodeType node = make_shared<NodeType>(key, value);
        PNodeType next = head_->next;
        node->next = next;
        next->pre = node;
        head_->next = node;
        node->pre = head_;
    }

    PNodeType pop(){
        PNodeType target = tail_->pre;
        if(target == head_)
            return NullNode;
        PNodeType pre = target->pre;
        pre->next = tail_;
        tail_->pre = pre;
        return target;
    }

    PNodeType move_to_head(PNodeType node){
        PNodeType pre  = node->pre;
        PNodeType next = node->next;
        pre->next = next;
        next->pre = pre;

        next = head_->next;
        
        node->next = next;
        next->pre = node;
        node->pre = head_;
        head_->next = node;
    }

public:
    static const PNodeType NullNode = make_shared<NodeType>();
private:
    PNodeType head_;
    PNodeType tail_;
};

template<typename K, typename V>
class LRUCache {
public:
    using PNodeType = shared_ptr<BiNode<K, V>>;
public:

    LRUCache(int cap):cap_(cap){};
    PNodeType get(int key){
        if(dict_.count(key)){
            PNodeType node = dict_[key];
            list_.move_to_head(node);
            return node;    
        }
        
        return LRUList<K, V>::NullNode;
    }

    void set(int key, int val){
        PNodeType cur = nullptr;
        
        if(dict_.count(key)){
            cur = dict_[key];
            cur->value = val;
        }else{
            if(dict_.size() == cap_){
                auto del_node = list_.pop();
                dict_.erase(del_node->key);
            }
            cur = list_.add(key, val);
            dict_[key] = cur;
        }
        list_.move_to_head(cur);
    }

private:
    size_t cap_ = 0;
    LRUList<K, V> list_ = {};
    unordered_map<K, BiNode<K, V>> dict_ = {};
};




int main() {
    return 0;
}