// https://leetcode-cn.com/problems/mini-parser/
// mini parser
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ns;
        if(s.size() == 0)
            return ns;
     

        if(s[0] != '['){
            ns.setInteger(stoi(s));
            return ns;
        }


        s = s.substr(1, s.size() - 2);

        if(s.size() == 0)
            return ns;

        int count = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[' || s[i] == ']' || s[i] == ','){
                if(s[i] == '[')
                    count++;
                if(s[i] == ']')
                    count--;
                if(count == 0){
                    int len = i - start;
                    if(s[i] == ']')
                        len = len + 1;
                    if(len != 0) {
                        ns.add(deserialize(s.substr(start, len)));
                    }
                    start = i + 1;
                }
            }
        }

        if(start != s.size()){
            ns.add(deserialize(s.substr(start, s.size() - start)));
        }
        return ns;
    }
};