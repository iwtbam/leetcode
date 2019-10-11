#include <vector>
#include <string>

using namespace std;

#if defined(S1)


// 意外之喜 Rabin-Karp竟然效果还不错 4ms 99.3%

class Solution {
public:
    
    inline bool check(const string& haystack, const string& needle, int pos)
    {
        int len = needle.size();
        for(int i = 0; i < len; i++)
            if(haystack[i + pos] != needle[i])
                return false;
        return true;
    }
    
    int strStr(string haystack, string needle) {
        int len1 = needle.size();
        int len2 = haystack.size();
        int q = 29;
        int base = 128 % q;
        base = (long long)pow(base, len1 - 1) % q;
        
        long long num1 = 0;
        long long num2 = 0;
        
        int i = 0;
        
        for(; i < len1; i++)
        {
            num2 = (num2 * 128 + haystack[i])%q;
            num1=  (num1 * 128 + needle[i])%q;
        }
        
        if(num1 == num2 && check(haystack, needle, 0))
            return 0;
        
        for(i = 1; i < len2 - len1 + 1; i++)
        {
            
            num2 = ((num2 - haystack[i - 1]  * base) * 128 + haystack[i + len1 - 1])%q;
            if(num2 < 0)
                num2 += q;
            if(num2 == num1 && check(haystack, needle, i))
               return i;
        }
        
        return -1;
        
    }
};


#elif defined(S2)
class Solution {
public:

//KMP 4ms 我一直以为KMP 要比 Rabin-Karp 要优很多, 然后并没有, 都差不多o(N)的复杂度    
    vector<int> getNext(const string& pattern)
    {
        int len = pattern.size();
        vector<int> next(len, 0);
        next[0] = -1;
        
        int i = 0;
        int j = -1;
        
        while(i < len - 1)
        {
            if(j == -1 || pattern[i] == pattern[j])
                if(pattern[++i] == pattern[++j])
                    next[i] = next[j];
                else
                    next[i] = j;
            else
                j = next[j];
        }
        
        return std::move(next);
    }
    
    int strStr(string haystack, string needle) {
      
        int len1 = haystack.size();
        int len2 = needle.size();
        
        if(len2 == 0)
            return 0;
        
        if(len2 > len1 || len1 == 0)
            return -1;
        
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        
        while(i < len1 && j < len2)
        {
            if(j == -1 || haystack[i] == needle[j])
                i++, j++;
            else
                j = next[j];
        }
        
        if(j == len2)
            return i - j;
        return -1;
    }
};

#endif