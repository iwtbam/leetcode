// 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int co = 0, sum = 0, len1 = 1, len2 = 1;
        ListNode* node1 = l1, *node2 = l2, *head,*pre;
        while((node1 = node1->next) && len1++);
        while((node2 = node2->next) && len2++);

        node1 = len1 > len2 ? l1 : l2;
        node2 = len1 > len2 ? l2 : l1;

        head = node1;

        while(node2)
        {
            node1->val = node1->val + node2->val + co;
            co  = node1->val / 10;
            node1->val = node1->val - co * 10;
            pre = node1;
            node2 = node2->next;
            node1 = node1->next;
        } 

        while(co && node1)
        {
            node1->val = node1->val + co;
            co  = node1->val / 10;
            node1->val = node1->val - co * 10;
            pre = node1;
            node1 = node1->next;
            cout << co << endl;
        }

        if(co)
        {
            ListNode* node = new ListNode(co);
            pre->next = node;
            node->next = nullptr;
        }

        return head;
    }
};

int main()
{
    return 0;
}