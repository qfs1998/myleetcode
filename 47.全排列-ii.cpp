/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        do{
            v.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return v;
    }
};

