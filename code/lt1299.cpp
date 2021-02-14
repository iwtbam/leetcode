// https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/
// replace elements with greatest element on right side
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int right = -1;
        int size = arr.size();
        for(int i = size - 1; i >= 0; i--){
            int e = arr[i];
            arr[i] = right;
            right = max(e, right);
        }
        
        return arr;
    }
};