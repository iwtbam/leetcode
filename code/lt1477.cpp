// https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// find two non overlapping sub arrays each with target sum
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0, right = 0, size = arr.size(), sum = 0;
       // int l1 = size + 1, l2 = size + 1;
        bool issame = true;
        for(int i = 1; i < size; i++){
            if(arr[i] != arr[0]){
                issame = false;
                break;
            }
        }
        
        if(issame){
            if(target * 2 <= arr[0] * size && target % arr[0] == 0)
                return target / arr[0] * 2;
            return -1;
        }
        
        vector<pair<int, int>> cans = {};
        while(right < size){
            
            sum += arr[right];
                
            
            while(left <= right && sum > target){
                sum -= arr[left++];
            }
            
            if(sum == target){
                cans.push_back({left, right});
            }
            
            
            right++;
        }
        
        
        if(cans.size() < 2){
            return -1;   
        }
        
        sort(cans.begin(), cans.end(), [](const pair<int, int>& p1, const pair<int,int>& p2){
            return p1.second - p1.first < p2.second - p2.first;
        });
        
     
        
        int ans = size + 1;
        
        int csize = cans.size();
        
    
        for(int i = 0; i < csize; i++){
            for(int j = 1; j < csize; j++){
                
                if(cans[j].first >= cans[i].first && cans[j].first <= cans[i].second)
                    continue;
                if(cans[i].first >= cans[j].first && cans[i].first <= cans[j].second)
                    continue;
                
                ans = min(ans, cans[j].second - cans[j].first + cans[i].second - cans[i].first + 2);
                break;
            }
            // if(ans != size + 1)
            //     break;
        }
        
        return ans == size + 1 ? -1 : ans;
    }
};