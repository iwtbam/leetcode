// https://leetcode-cn.com/problems/sparse-array-search-lcci/
// sparse array search lcci
class Solution {
public:
    int findString(vector<string>& words, string s) {
        int size = words.size();
        int l = 0, r = size;
        while(l < r){
            int mid = l + (r - l) / 2;
            int temp = mid;
            while(temp >= 0 && words[temp] == "")
                temp--;
            if(temp == -1){
                temp = mid + 1;
                while(temp < size && words[temp] == "")
                    temp++;
                if(temp == size)
                    return -1;
            }

            if(words[temp] == s)
                return temp;
            
            if(words[temp] > s){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return -1;
    }
};