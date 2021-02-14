
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur && next)
        {
            swap(cur->val, next->val);
            cur = next->next;
            next = cur ? cur->next : nullptr;
        }

        return head;
    }

    inline void swap(int& a, int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};