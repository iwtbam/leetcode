// https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree/
// verify preorder sequence in binary search tree
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> is;
        int min = INT_MIN;
        int size = preorder.size();
        for(int i = 0; i < size; i++)
        {
            if(preorder[i] < min)
                return false;
            while(is.size() && preorder[i] > is.top())
            {
                min = is.top();
                is.pop();
            }

            is.push(preorder[i]);
        }
        return true;
    }
};