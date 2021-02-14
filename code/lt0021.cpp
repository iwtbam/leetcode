struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* mergeTowLists(ListNode* l1, ListNode* l2){
      

        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while(l1 && l2)
        {
            cur->next = new ListNode(getNextVal(l1, l2));
            cur = cur->next;
        }

        while(l1)
        {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }

        while(l2)
        {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }

        return head->next;
    }

    inline int getNextVal (ListNode* l1, ListNode* l2){
        
        int nextVal = l1->val;

        if(l1->val > l2->val)
        {
            nextVal = l2->val;
            l2 = l2->next;
        }
        else
            l1 = l1->next;
        return nextVal;
    }
};