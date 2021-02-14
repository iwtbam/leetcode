// https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/
// find k th smallest pair distance
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        
        while(l < r){
            int mid = (l + r) >> 1;
            if(count(nums, mid) >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int count(const vector<int>& nums, int dis){
        int l = 0, r = 0, size = nums.size();
        int ret = 0;
        while(r < size){
            while(l <= r && nums[r] - nums[l] > dis){
                l++;
            }

            if(nums[r] - nums[l] <= dis){
                ret += r - l;
                // for(int i = l; i < r; i++){
                //     cout << "(" << nums[i] << "," << nums[r] << ")";
                // }
            }
            r++;
        }

      
        // cout << endl;

        return ret;
    }
};