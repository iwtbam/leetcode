// https://leetcode-cn.com/problems/design-search-autocomplete-system/
// design search autocomplete system
struct TiredNode {
    int fred;
    unordered_map<char, TiredNode*> children;
    TiredNode(int f = 0):fred(f){}
};


using TiredNodeRecord = pair<int, string>;

struct Cmp {
    bool operator()(const TiredNodeRecord& p1, const TiredNodeRecord& p2){
        return p1.first == p2.first ? p1.second < p2.second  : p1.first > p2.first;
    }
};


class TiredTree {

public:
    void add(const string& prefix, int fred){
        int size = prefix.size();
        TiredNode* node = &root;
        for(int i = 0; i < size; i++){
            char c = prefix[i];
            if(node->children.count(c) != 1){
                node->children[c] = new TiredNode();
            }
            node = node->children[c];
        }
        node->fred += fred;
    }

    TiredNode* getRoot(){
        return &root;
    }

    TiredNode* getNext(TiredNode* node, char c){
        if(node == nullptr || node->children.count(c) == 0)
            return nullptr;
        return node->children[c];
    }

    vector<string> getWords(string prefix, TiredNode* node){
        vector<pair<int, string>> record = {};
        helper(record, prefix, node);
        return top3(record);
    }


private:
    vector<string> top3(const vector<pair<int, string>>& record){   
        int size = record.size();
        priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp> q;
        Cmp cmp;
        for(int i = 0; i < size; i++){
            if(q.size() < 3){
                q.push(record[i]);
            }else{
                if(cmp(record[i], q.top())){
                    q.pop();
                    q.push(record[i]);
                }
            }
        }

        size = min(3, static_cast<int>(q.size()));
        vector<string> res(size);
        for(int i = size - 1; i >= 0; i--){
            res[i] = q.top().second;
            q.pop();
        }

        return res;
    }



    void  helper(vector<pair<int, string>>& res, string& prefix, TiredNode* node){
        if(node == nullptr)
            return;
        
        if(node->fred != 0){
            res.push_back({node->fred, prefix});
        }

        auto& children = node->children;
        for(auto& [K, child] : children){
            prefix.push_back(K);
            helper(res, prefix, child);
            prefix.pop_back();
        }
    }

private:
    TiredNode root;
};


class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int size = sentences.size();
        for(int i = 0; i < size; i++){
            tree.add(sentences[i], times[i]);
        }
        cur = tree.getRoot();
    }
    
    vector<string> input(char c) {

        if(c == '#'){
            tree.add(prefix, 1);
            cur = tree.getRoot();
            prefix = "";
            return {};
        }

        prefix.push_back(c);
        cur = tree.getNext(cur, c);
        return tree.getWords(prefix, cur); 
    }

private:
    TiredTree tree;
    TiredNode* cur;
    string prefix;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */