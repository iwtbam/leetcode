#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution {
public:

    struct ListNodeCmp
    {
        bool operator()(ListNode* el1,ListNode* el2)
        {
            return el1->val < el2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> con;
        size_t size = lists.size();
        for(auto node:lists){
            if(node)
                con.push(node);
        }       

        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while(con.size())
        {
            ListNode* front = con.top();
            con.pop();
            cur->next = new ListNode(front->val);
            front = front->next;
            if(front)
                con.push(front);
            cur = cur->next;
        }

        return head->next;
    }
};