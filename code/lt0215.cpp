#include <vector>
#include <queue>

using namespace std;



#if defined S1

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int size = nums.size();
        
        for(int i = 0; i < k; i++)
            heap.push(nums[i]);
        
        for(int i = k; i < size; i++)
        {
            if(nums[i] > heap.top()){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        
        return heap.top();
    }
};

#elif defined S2

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(0, nums.size() - 1, k , nums);
    }

    int helper(int left, int right, int k, vector<int>& nums){
        if(left == right)
            return nums[left];

        int pivot_index = partition(left, right, nums);
        if(pivot_index == k - 1)
            return nums[pivot_index];
        else if(pivot_index > k - 1)
            return helper(left, pivot_index - 1, k, nums);
        else
            return helper(pivot_index + 1, right, k, nums);
        
    }

    int partition(int start, int end, vector<int>& nums)
    {
        int pivot_index = start;
        int pivot_val = nums[pivot_index];
        int l = start + 1, r = end;
        while(l < r)
        {
            for(;l < r && nums[r] < pivot_val; r--);
            for(;l < r && nums[l] >= pivot_val;l++);
            if(l < r)
                swap(nums[l], nums[r]);
        }
        
        if(nums[pivot_index] > nums[l])
            return pivot_index;
        
        swap(nums[pivot_index], nums[l]);
        return l;
    }

    inline void swap(int& a, int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

#endif