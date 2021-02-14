// https://leetcode-cn.com/problems/list-of-depth-lcci/
// list of depth lcci
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> nodes;
        queue<TreeNode*> q;
        q.push(tree);
        ListNode dumpy;
        while(q.size()){
            int size = q.size();
            ListNode* cur = &dumpy;
            for(int i = 0; i < size; i++){
                TreeNode*  front = q.front();
                q.pop();
                cur->next = new ListNode(front->val);
                cur = cur->next;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            nodes.emplace_back(dumpy.next);
        }
        return nodes;
    }
};