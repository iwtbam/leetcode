import java.util.*;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */

class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int d = deep(nestedList);
        // System.out.println(d);
        return helper(nestedList, d);
    }
    
    
    public int helper(List<NestedInteger> nestedList, int d){
        int res = 0;
        for(NestedInteger ni : nestedList){
            if(ni.isInteger())
                res += ni.getInteger() * d;
            else
                res += helper(ni.getList(), d - 1);
        }
        
        return res;
    }
    
    public int deep(List<NestedInteger> nestedList){
        
        int deep = 1;
        
        for(NestedInteger ni: nestedList){
            if(!ni.isInteger())
                deep = Math.max(deep, deep(ni.getList()) + 1) ;
        }
        
        return deep;    
    }
