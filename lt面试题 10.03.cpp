// https://leetcode-cn.com/problems/search-rotate-array-lcci/
// search rotate array lcci
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(arr[l] == target)
                return l;
            
            if(arr[mid] == target)
                r = mid;
            else if(arr[mid] > arr[l]){
                if(arr[l] <= target && target <= arr[mid])
                    r = mid;
                else
                    l = mid + 1;
            }else if(arr[mid] < arr[l]){
                if(arr[mid] <= target && target  <= arr[r])
                    l = mid + 1;
                else
                    r = mid;
            }else if(arr[mid] == arr[l]){
                l = l + 1;
            }
        }

        return arr[l] == target ? l : -1;
    }
};