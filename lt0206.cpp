struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = head;
        while(next)
        {
            ListNode* temp = next->next;
            next->next = pre;
            pre = next;
            next = temp;
        } 

        return pre;       
    }
};