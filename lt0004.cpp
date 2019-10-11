#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n)
            nums1.swap(nums2);

        m = nums1.size();
        n = nums2.size();

        int i_min = 0, i_max = m, half_len = (m + n + 1) / 2;

        while(i_min <= i_max)
        {
            int i = (i_min + i_max) / 2;
            int j = half_len - i;
            if(i < i_max && nums2[j - 1] > nums1[i]){
                i_min = i + 1;
            }else if(i > i_min && nums2[j] < nums1[i - 1]){
                i_max = i - 1;
            }else{
                int max_left = 0;
                if(i == 0){
                    max_left = nums2[j-1];
                }else if(j == 0){
                    max_left = nums1[i-1];
                }else{
                    max_left = max(nums1[i-1], nums2[j-1]);
                }


                if((m+n)%2==1)
                    return max_left;

                int min_right = 0;

                if(i == m){
                    min_right = nums2[j];
                }else if(j == n){
                    min_right = nums1[i];
                }else{
                    min_right = min(nums1[i], nums2[j]);
                }

                return (max_left + min_right) / 2;
            }
        }

        return 0.0;
    }
};

int main()
{
    return 0;
}