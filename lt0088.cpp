#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int size = m + n;
        int p1 = m -1, p2 = n - 1, pt = size - 1;

        for(; pt >=0; pt--)
        {
            
            if(p1 < 0 || p2 < 0)
                break;

            if(nums1[p1] > nums2[p2])
                nums1[pt] = nums1[p1--];
            else
                nums1[pt] = nums2[p2--]; 
        }

        if(p1 < 0)
        {
            while(pt >=0)
            {
                nums1[pt] = nums2[p2];
                pt--;
                p2--;
            }
        }
    }

};