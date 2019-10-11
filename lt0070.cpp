// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 注意：给定 n 是一个正整数。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2;

        // 传说中的左脚右脚上青天
        for(int i = n; i >=3; i--){
            a = a + b;
            a = a + b;
            b = a - b;
            a = a - b;
        }
        if(n == 1)
            return a;
        return b;

    }
};