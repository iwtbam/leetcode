// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
// er cha sou suo shu de hou xu bian li xu lie lcof
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size());
    }

    bool verifyPostorder(vector<int>& postorder, int l, int r){
        if(r - l <= 0)
            return true;
        
        int pivot = postorder[r - 1];

        int pos = l;
        while(pos < r - 1 && postorder[pos] < pivot)
            pos++;

        int pos2 = pos;
        while(pos2 < r - 1 && postorder[pos2] >= pivot)
            pos2++;

        if(pos2 < r - 1)
            return false;
        
        return verifyPostorder(postorder, l, pos) && verifyPostorder(postorder, pos, r - 1);
    }
};