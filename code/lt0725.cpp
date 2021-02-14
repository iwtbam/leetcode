// https://leetcode-cn.com/problems/split-linked-list-in-parts/
// split linked list in parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* node = root;
        while(node){
            len++;
            node = node->next;
        }

        int seg = len / k;
        int mod = len % k;
        vector<ListNode*> nodes = {};

        node = root;

        while(node){
            int num = seg + (mod-- > 0 ? 1 : 0);
            nodes.push_back(node);

            // cout << num << endl;

            while(num-- && node){
                ListNode* next = node->next;
                if(num == 0)
                    node->next = nullptr;
                node = next;
            }
        }
        // cout << k << " " << nodes.size() << endl;
        int size = nodes.size();
        for(int i = 0; i < k - size; i++){
         //   cout << i << endl;
            nodes.push_back(nullptr);
        }

        return nodes;

    }
};