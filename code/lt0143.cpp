// https://leetcode-cn.com/problems/reorder-list/
// reorder list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur != nullptr){
            nodes.push_back(cur);
            cur = cur->next;
        }

        ListNode dumpy;
        ListNode* p = &dumpy;
        int size = nodes.size();
        int half = nodes.size() / 2 + nodes.size() % 2;
        
        for(int i = 0; i < half; i++){
            p->next = nodes[i];
            p = p->next;
            if(i + half <= size){
                p->next = nodes[size - i - 1];
                p = p->next;
            }
            p->next = nullptr;
        }

        // return dumpy.next;
        return;
    }
};