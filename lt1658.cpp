// https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/
// minimum operations to reduce x to zero
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> rights;
        int size = nums.size();
        rights.push_back(0);
        for(int i = size - 1; i >= 0; i--){
            rights.push_back(rights.back() + nums[i]);
        }
        
        reverse(rights.begin(), rights.end());
        
        int pos = search(rights, x);
        
        
        int times = (pos == UN_SOLVE ? UN_SOLVE : size - pos);
        int sum = 0;
        for(int i = 0; i < size - 1; i++)
        {
            sum += nums[i];
            pos = search(rights, x - sum);
            if(pos != UN_SOLVE && pos > i){
                times = min(times, i + 1 + size - pos);
            }
        }
        
        return times == UN_SOLVE ? -1 : times;
    }
    
    int search(const vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return UN_SOLVE;
    }
    
private: 
    
    const int UN_SOLVE = INT_MAX;
    

};