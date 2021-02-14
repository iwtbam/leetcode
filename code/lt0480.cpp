#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> lo;
        priority_queue<int, deque<int>, greater<int>> hi;

        unordered_map<int, int> mark = {};

        vector<double> res = {};

        size_t size = nums.size();

        for(int i = 0; i < k; i++){
            lo.push(nums[i]);
        } 

        for(int i = 0; i < k / 2; i++){
            hi.push(lo.top());
            lo.pop();
        }

        double mid = k % 2 == 0 ? (lo.top() + hi.top()) / 2.0 : lo.top();
        res.push_back(mid);

        for(int i = k; i < size; i++){
         
            int out_num = nums[i - k];
            int in_num = nums[i];
            mark[out_num]++;

            int blance = out_num <= lo.top() ? -1 :  1;

            if(lo.size() > 0 && in_num <= lo.top()){
                lo.push(in_num);
                blance++;
            }else{
                hi.push(in_num);
                blance--;
            }

            if(blance > 0){
                hi.push(lo.top());
                lo.pop();
                blance--;
            }

            if(blance < 0){
                lo.push(hi.top());
                hi.pop();
                blance++;
            }

            while(lo.size() > 0 && mark[lo.top()] > 0){
                mark[lo.top()]--;   
                lo.pop();
            }

            while(hi.size() > 0 && mark[hi.top()] > 0){
                mark[hi.top()]--;
                hi.pop();
            }

            mid = k % 2 == 0 ? (lo.top() + hi.top()) / 2.0 : lo.top();
            res.push_back(mid);
        }

        return res;
    }
};