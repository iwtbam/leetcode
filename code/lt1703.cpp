// https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
// minimum adjacent swaps for k consecutive ones
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int l = 0, r = 0;
        size_t size = nums.size();
        int record[2] = {0, 0};
        int move = INT_MAX;
        
        sums.resize(size + 1, 0);
        
        for(int i = 0; i < size; i++){
            if(nums[i] == 1){
                sums[i + 1] = sums[i] + i;
            }else{
                sums[i + 1] = sums[i];
            }
        }
        
        // for(int i = 0; i < size; i++){
        //     cout << sums[i + 1] << " ";
        // }
        // cout << endl;
        
        
        deque<int> ones;
        
        
        while(r < size){
            record[nums[r]]++;
            
            if(nums[r] == 1){
                ones.push_back(r);
            }
            
            while(l <= r && record[1] > k){
                record[nums[l]]--;
                if(ones.size() && l >= ones.front())
                    ones.pop_front();
                l++;
            }
            
            if(record[1] >= k){
                move = min(move, calc_cost(ones));
            }
            
            r++;
        }
        
        if(record[1] >= k)
            move = min(move, calc_cost(ones));
        
        return move;
    }
    
    int calc_cost(const deque<int>& ones){
        
        if(ones.size() == 0)
            return 0;
        
        int L = 0;
        int R = ones.size();
        int mid = L + (R - L) / 2;
        
     //   cout << ones[L] << " " << ones[R - 1] << endl;
        
        long long cost = (sums[ones[R - 1] + 1] - sums[ones[mid] + 1]) - (sums[ones[mid]] - sums[ones[L]]);
        
       // cout << cost << endl;
        
        if(R % 2 == 0)
            cost += ones[mid];
        
        cost = cost - (R - mid - 1) * (R - mid) / 2;
        cost = cost - ((mid - L) * (mid - L + 1) / 2); 
        return cost;
    }
    
private:
    vector<int> ones;
    vector<long long> sums;
    
};