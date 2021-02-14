// https://leetcode-cn.com/problems/clone-graph/
// clone graph
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr)
            return nullptr;
        
        if(clone_record.count(node))
            return clone_record[node];

        Node* cloneNode = new Node();
        cloneNode->val = node->val;
        clone_record[node] = cloneNode;
        size_t size = node->neighbors.size();
        for(int i = 0; i < size; i++)
            cloneNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return cloneNode;
    }
private:
    unordered_map<Node*, Node*> clone_record;
};