// https://leetcode-cn.com/problems/evaluate-division/
// evaluate division

class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      int size = equations.size();
      for(int i = 0; i < size; i++){
          merge(equations[i][0], equations[i][1], values[i]);
      }
      int q = queries.size();
      vector<double> res = {};
      for(int i = 0; i < q; i++){
          res.push_back(getValue(queries[i][0],queries[i][1]));
      }
      return res;
    }

    void init(const string& key){
        if(!graph.count(key)){
            graph[key] = key;
            vals[key] = 1.0;
        }
    }

    string parent(const string& node){
        if(graph[node] !=node){
            string t = parent(graph[node]);
            vals[node] *= vals[graph[node]];
            graph[node] = t; 
        }
        return graph[node];
    }

    void merge(const string& node1, const string& node2, double val){
        init(node1);
        init(node2);
        string p1 = parent(node1);
        string p2 = parent(node2);
        graph[p2] = p1;
        vals[p2] = vals[node1] * val / vals[node2];
    }

    double getValue(const string& node1, const string& node2){
        if(!graph.count(node1) || !graph.count(node2))
            return -1.0;
        string p1 = parent(node1);
        string p2 = parent(node2);
        if(graph[node1] != graph[node2])
            return -1.0;
        return vals[node2] / vals[node1];
    }

    
    unordered_map<string, string> graph = {};
    unordered_map<string, double> vals = {};
    // int num
    

};