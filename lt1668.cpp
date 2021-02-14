// https://leetcode-cn.com/problems/maximum-repeating-substring/
// maximum repeating substring
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string pattern = "";
        
        int k = 0;
        
        while(sequence.find(pattern + word) != string::npos){
            pattern += word;
            k++;
        }
        
        return k;
    }
};