/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        vector<int>v(A);
        if(!prev_permutation(A.begin(),A.end()))
            return v;
        return A;
    }
};

