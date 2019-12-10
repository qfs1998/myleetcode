/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    // bool isPowerOfTwo(int n) {
    //     int sum=0;
    //     //需要n>0因为如果是负数的话，右移左边添加的是1，无穷循环
    //     while(n>0){
    //         sum=sum+(n&1);
    //         n=n>>1;
    //     }
    //     return sum==1;
    // }
    
        bool isPowerOfTwo(int n) {
            //eg: 1000  0111
            return (n>0) && (n&(n-1))==0;
    }
};
// @lc code=end

