#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        size_t left = 0, right = 0, size1 = s1.size(), size2 = s2.size();
        
        int record[26] = {0};
        
        for(int i = 0; i < size1; i++){
            record[s1[i] - 'a']++;
        }
        
        while(right < size2){
            int index = s2[right] - 'a';
            record[index]--;
            while(check(record) == -1 && left <= right){
                record[s2[left] - 'a']++;
                left++;        
            }
            if(check(record)==0)
                return true;
            right++;
        }

        return false;

    }

    int check(int* record){
        int flag = 0;
        for(int i = 0; i < 26; i++){
            if(record[i] < 0)
                return -1;
            if(record[i] > 0)
                flag = 1;
        }
        return flag;
    }
};