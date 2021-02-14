#include <iostream>
#include <vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p == nullptr && q == nullptr)
            return true;

        if(p == nullptr && q!=nullptr)
            return false;

        if(p !=nullptr && q == nullptr)
            return false;
        
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }
};

int main()
{
    int* a = nullptr;
    int* b = nullptr;
    cout << (a == b) << endl;
    return 0;
}

