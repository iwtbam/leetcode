#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr) ,right(nullptr){};
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        helper(root);
        vector<int> record = {};
        vector<int> res = {};
        for(auto& p:cache){
            record.push_back(p.second);
        }
        
        sort(record.begin(), record.end());
        
        
        int max_count = 1;
        int cur_count = 1;
        for(int i = 1; i < record.size(); i++)
        {
            if(record[i] == record[i-1])
                cur_count++;
            else
            {
                max_count = max(max_count, cur_count);
                cur_count = 1;
            }
        }
        
        max_count = max(max_count, cur_count);


        cur_count = 1;
        int temp = 1;
        for(int i = 1; i < record.size(); i++)
        {
            if(record[i] == record[i-1]){
                cur_count++;
            }else{
                if(max_count == cur_count)
                    res.push_back(record[i-1]);
                cur_count = 1;
            }
        }
        
       
        if(max_count == cur_count)
            res.push_back(record.back());
            
        return res;
    }
    
    int helper(TreeNode* root){
        if(root == nullptr)
            return 0;
  
        
        int lV = cache.find(root->left) != cache.end() ? cache[root->left] : helper(root->left);
        int rV = cache.find(root->right)!= cache.end() ? cache[root->right]: helper(root->right);
        cache[root] = root->val + lV + rV;
        return cache[root];
        
    }
    
private:
    map<TreeNode*, int> cache = {};
};