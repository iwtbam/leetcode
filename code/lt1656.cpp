// https://leetcode-cn.com/problems/design-an-ordered-stream/
// design an ordered stream
class OrderedStream {
public:
    OrderedStream(int n) {
        strs.resize(n);
        vis.resize(n);
        this->n = n;
    }
    
    vector<string> insert(int id, string value) {
        strs[id - 1] = value;
        vis[id - 1] = 1;
        if(ptr == id - 1){
            vector<string> res;
            while(ptr < n && vis[ptr]){
                res.push_back(strs[ptr]);
                ptr++;               
            }
            return res;
        }
        return {};
    }
    
private:
    vector<string> strs;
    vector<bool> vis;
    int ptr = 0;
    int n = 0;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */