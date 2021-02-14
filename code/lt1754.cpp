// https://leetcode-cn.com/problems/largest-merge-of-two-strings/
// largest merge of two strings
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0, j = 0, s1 = word1.size(), s2 = word2.size();
        
        while(i < s1 && j < s2){            
            if(word1.substr(i) > word2.substr(j))
                merge.append(1, word1[i++]);
            else
                merge.append(1, word2[j++]);
        }
        
        if(i < s1)
            merge.append(word1.substr(i));
        
        if(j < s2)
           merge.append(word2.substr(j)); 
        
        return merge;
    }
};