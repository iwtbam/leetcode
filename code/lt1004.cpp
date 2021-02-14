#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int size = A.size();
        int left = 0, right = 0, max_cnt = INT_MIN, cur_num = 0;
        
        while(right < size)
        {
            if(A[right])
                cur_num++;
            max_cnt = max(cur_num, max_cnt);
            if(right - left + 1 - max_cnt > K)
            {
                if(A[left++])
                    cur_num--;
            }
            right++;
        }

        return max_cnt + K > A.size() ? A.size() : max_cnt + K;
    
    }
};