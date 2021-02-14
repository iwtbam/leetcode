// https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch/
// number of students unable to eat lunch
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int nums1[2] = {0, 0}, nums2[2] = {0, 0};
        size_t size = students.size();
        for(int i = 0; i < size; i++){
            nums1[students[i]]++;
        }
        
        int bit = 0;
        
        for(int i = 0; i < size; i++){
            int n = sandwiches[i];
            nums2[n]++;
            if(nums2[n] > nums1[n]){
                bit = 1;
                break;
            }
        }
        
        return size - (nums2[0] + nums2[1] - bit);
    }
};