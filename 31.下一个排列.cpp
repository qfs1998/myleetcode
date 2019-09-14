/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!next_permutation(nums.begin(),nums.end()))
            sort(nums.begin(),nums.end());
    }
};

