// https://leetcode-cn.com/problems/building-boxes/
// building boxes
/*
1 1
2 2
3 3
4 3
5 4
6 4
7 
*/


class Solution {
public:
    const int len = 1e5;
    vector<long long> nums;
    Solution(){
        nums.resize(len + 1, 0);
        for(int i = 1; i <= len; i++)
            nums[i] = nums[i - 1] + 1LL * i * (i + 1) / 2;
   
    }
    
    int bin(int n){
        int l = 0, r = len;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            //cout << mid << " " << nums[mid] <<  " " << n << endl; 
            if(n >= nums[mid])
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    
    int minimumBoxes(int n) {
        
        long long pos = bin(n);
        long long count = pos * (pos + 1) / 2; 
        long long res = n - nums[pos];
        int r = ceil((-1.0 + sqrt(1.0 + 8.0 * res)) /2.0);
        return count + r;
    }
};