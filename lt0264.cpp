#include <queue>
#include <algorithm>

using namespace std;

#if defined S1

//2019-07-31:18-50 不优

class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long long, vector<long long>, greater<long long>> q;
        vector<int> nums = {2, 3, 5};
        q.push(1);
        long long pre = -1;
        for(int i = 0; i < n - 1; i++)
        {
            while(pre == q.top())
                q.pop();
            long long top = q.top();
            q.pop();
            pre = top;
            for(int i = 0; i < 3; i++)
                q.push(nums[i] * top);
        }
        
        while(pre == q.top())
            q.pop();
        return q.top();
    }
};


#elif defined S2
//2019-07-31:52 题解有人写的dp,说实话这感觉不是dp吧, 三指针倒是不错

class Solution
{
    public:
    int nthUglyNumber(int n){
        vector<int> res = {1};
        int i2 = 0, i3 = 0, i5 = 0, i = 1;
        while(i < n)
        {
            int temp = min(2*res[i2], min(3*res[i3], 5*res[i5]));
            res.push_back(temp);
            if(temp==2*res[i2]) 
                i2++;
            if(temp==3*res[i3]);
                i3++;
            if(temp==5*res[i5]);
                i5++;
        }

        return res.back();
    }
};

#endif