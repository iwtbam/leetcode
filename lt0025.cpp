struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr || k<2)
            return head;
        
        ListNode* cur = head;
        ListNode* next = getNextKNode(cur, k - 1);
        ListNode* nHead = head;
        ListNode* nnext = next ? next->next : nullptr;
        if(cur && next)
        {
            nHead = reverseHelper(cur, k);
        }
        
        next = nnext;
        
        while(cur && next)
        {
            nnext = getNextKNode(next, k - 1);
            ListNode* temp = nnext ? nnext->next : nullptr;
            if(nnext)
                cur->next = reverseHelper(next, k);
            else
                cur->next = next;
            cur = next;
            next = temp;
           
        }
    
        return nHead;
    }
    
    ListNode* getNextKNode(ListNode* cur, int k)
    {
        ListNode* next = cur;
        int i = 0;
        while(i < k && next)
        {
            next = next->next;
            i++;
        }
        
        if(i!=k)
            return nullptr;
        
        return next;
    }

    ListNode* reverseHelper(ListNode* head, int k){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        int i = 0;
        while(i < k && cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            i++;
        }    

        return pre;
    }
};
