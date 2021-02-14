struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr)
            return nullptr;
        
        ListNode* lp = head;
        ListNode* fp = head;
        int len = 0;
        do
        {
            lp = lp->next;
            fp = fp->next;
            if(fp == nullptr)
                return nullptr;
            fp = fp->next;
            
            len++;
        } while (lp!=nullptr && fp!=nullptr && fp != lp);
        
        if(fp == nullptr || lp == nullptr)
            return nullptr;

        lp = head;
        fp = head;

        for(int i = 0; i < len; i++)
            fp = fp->next;

        while(lp!=fp)
        {
            lp = lp->next;
            fp = fp->next;
        }

        return lp;
    }
};