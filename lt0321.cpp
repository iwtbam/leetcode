#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if(k >= nums1.size() + nums2.size()){
            return merge(move(nums1), move(nums2), k);
        }
        
        if(nums1.size() < nums2.size())
            nums1.swap(nums2);
        
        int s = k - min(static_cast<int>(nums2.size()), k);
        int maxK = min(k, static_cast<int>(nums1.size()));
        vector<int> res = merge(maxNumber(nums1, s), maxNumber(nums2, k - s), k);
        
        for(int i = s + 1; i <= maxK; i++)
        {  
            vector<int> temp = merge(maxNumber(nums1, i),  maxNumber(nums2, k - i), k);
            if(!gt(res,0, temp,0)){
                res = temp;
            }
        }
        
        return res;
    }
    
    vector<int> maxNumber(vector<int>& nums, int k)
    {
        vector<int> res(k ,0);
        int n = nums.size();
        
        for(int i = 0, j = 0; i < n; i++)
        {
            while(n - i + j > k && j > 0 && nums[i] > res[j - 1])
                j--;
            if(j < k)
                res[j++] = nums[i];
            
        }

        return res;
    }
    
    vector<int> merge(vector<int>&& nums1, vector<int>&& nums2, int k){
        
        vector<int> res(k, 0);
        
        for(int i = 0, j = 0, r = 0; r < k; r++){
            res[r] = gt(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        
        return res;
    }
    
    bool gt(vector<int>& nums1, int i, vector<int>& nums2, int j)
    {
        for(; i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]; i++, j++);
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]); 
    }
    
};