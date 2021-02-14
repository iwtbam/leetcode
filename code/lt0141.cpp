struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        
        if(head->next == nullptr)
            return false;

        ListNode* slow = head, *fast = head->next;

        while(slow && fast && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }

        if(slow == nullptr || fast == nullptr)
            return false;
        return true;
    }
};