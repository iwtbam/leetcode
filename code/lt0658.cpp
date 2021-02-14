// https://leetcode-cn.com/problems/find-k-closest-elements/
// find k closest elements
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
 
        int l = 0, r = arr.size() - k;
        while(l < r){
            int mid = (l + r) >> 1;
            if(arr[mid + k] - x >= x - arr[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }

    
};