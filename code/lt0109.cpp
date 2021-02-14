// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
// convert sorted list to binary search tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> elements = {};
        while(head){
            elements.push_back(head->val);
            head = head->next;
        }
        return buildTree(std::move(elements));
    }

    TreeNode* buildTree(const vector<int>&& elements){
        if(elements.size() == 0)
            return nullptr;
        int mid = elements.size() / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = buildTree({elements.begin(), elements.begin() + mid});
        node->right = buildTree({elements.begin() + mid + 1, elements.end()});
        return node;
    }
};