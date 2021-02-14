// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
// flatten nested list iterator
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       int size = nestedList.size();
       for(int i = size - 1; i >= 0; i--){
           ns.push(nestedList[i]);
       }
    }
    
    int next() {
        int ret = ns.top().getInteger();
        ns.pop();
        return ret;
    }
    
    bool hasNext() {
        while(ns.size() && !ns.top().isInteger()){
            auto list = ns.top().getList();
            ns.pop();
            int size = list.size();
            for(int i = size - 1; i >= 0 ; i--){
                ns.push(list[i]);
            }
        }
        return ns.size();
    }

private:
    stack<NestedInteger> ns;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */