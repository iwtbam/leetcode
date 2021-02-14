// https://leetcode-cn.com/problems/word-transformer-lcci/
// word transformer lcci
class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        buildGraph(beginWord, wordList);

        if(graph.count(endWord) == 0)
            return {};

        queue<string> q;
        q.emplace(beginWord);
        dis[beginWord] = 0;

        while(q.size())
        {   
            string c = q.front();
            q.pop();
            vector<string> children = graph[c];
           // cout << c << " :" ;
            for(string child : children){
             //   cout << child << "/";
                if(dis.count(child) && dis[c] + 1 > dis[child])
                    continue;
                
                if(dis.count(child) && dis[c] + 1 == dis[child]){
                    parents[child].push_back(c);
                    continue;
                }
                parents[child].clear();
                parents[child].push_back(c);
                dis[child] = dis[c] + 1;
                q.emplace(child);
            }
            //cout << endl;
        }

        if(dis.count(endWord) == 0)
            return {};


        vector<string> path;
        vector<vector<string>> res;
        collects(endWord, beginWord, path, res);
        return res.back();

    }

    void collects(string& cur, const string& beginWord, vector<string>& path, vector<vector<string>>& res)
    {
        path.push_back(cur);
        if(cur == beginWord)
        {
            
            res.emplace_back(path.rbegin(), path.rend());
            path.pop_back();
            return;
        }


        for(auto parent : parents[cur]){
            collects(parent, beginWord, path, res);
        }
        path.pop_back();
    }

    void buildGraph(const string& beginWord, vector<string>& wordList)
    {
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);

        size_t size = wordList.size();
        size_t word_size = beginWord.size();

        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int cost = 0;

                for(int k = 0; cost <= 1 && k <word_size; k++)
                    cost += wordList[i][k] != wordList[j][k];
                
                if(cost <= 1){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
                
            }
        }

        // for(int i = 0;  i < size; i++)
        // {
        //     cout << wordList[i] << ":";
        //     for(string adj : graph[wordList[i]])
        //         cout << adj << " ";
        //     cout << endl;
        // }
    }

private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> dis;
    unordered_map<string, vector<string>> parents;
};