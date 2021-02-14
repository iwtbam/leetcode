// https://leetcode-cn.com/problems/find-closest-lcci/
// find closest lcci
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> record1;
        vector<int> record2;
        size_t size = words.size();
        for(int i = 0; i < size; i++){
            if(words[i] == word1){
                record1.push_back(i);
            }
            if(words[i] == word2){
                record2.push_back(i);
            }
        }

        int cur = 0;
        int dis = INT_MAX;
        size_t size1 = record1.size(), size2 = record2.size();
        for(int i = 0; i < size1 && dis > 0; i++){
            while(cur < size2 && record2[cur] < record1[i]){
                cur++;
            }
            
            if(cur > 0)
                dis = min(dis, abs(record2[cur - 1] - record1[i]));

            if(cur == size2)
                return dis;
            dis = min(dis, abs(record2[cur] - record1[i]));
        }

        return dis;
    }
};