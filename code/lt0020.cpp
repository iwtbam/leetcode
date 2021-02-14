// https://leetcode-cn.com/problems/valid-parentheses/
// valid parentheses
class Solution {
public:
    bool isValid(string s) {
        
        if(s.empty())
            return true;
        
        stack<char> os;
        os.push(s[0]);
        int size = s.size();
        for(int i = 1; i < size; i++)
        {
            if(os.size())
            {
                char top = os.top();
                if(pairs[top] == s[i])
                {
                    os.pop();
                }
                else
                    os.push(s[i]);
            }
            else
                os.push(s[i]);
        }

        return os.empty();
        
    }
    
private:
    unordered_map<char, char> pairs = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'}', '#'},
        {')', '#'},
        {']', '#'}
    };
};