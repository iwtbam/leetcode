#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

//2019-06-20:17-00 有点暴力 不好

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

struct less_pair
{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:

    using EleType    = pair<int, int>;
    using EleQueType = priority_queue<EleType, vector<EleType>, less_pair>; 
    vector<int> closestKValues(TreeNode* root, double target, int k) {
          EleQueType eles;
          vector<int> res;
          helper(eles, root, target);
          for(int i = 0; i < k; i++);
          {
              res.push_back(eles.top().first);
              eles.pop();
          }
          return res;
    }

    void helper(EleQueType& eles, TreeNode* root, double target){
        if(root)
        {
            helper(eles, root->left, target);
            eles.push({root->val, fabs(target - root->val)});
            helper(eles, root->right, target);
        }
    }
};