// https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/
// maximum length of subarray with positive product
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res = 0;
        int neg_num = 0, pos_num = 0, last = -1, start = 0;
        size_t size = nums.size();
        vector<int> negs = {};
        for(int i = 0; i < size; i++){
            if(nums[i] < 0){
                neg_num++;
                negs.push_back(i);
            }else if(nums[i] > 0){
                pos_num++;
            }else{
                pos_num = 0;
                neg_num = 0;
                negs.clear();
                start = i + 1;
            }
            
            if(neg_num % 2 == 0)
                res = max(res, pos_num + neg_num);
                
            else{
                res = max(res, max(i - negs.front() , negs.back() - start));
            }
        }
        
        return res;
    }
};