/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<nums.size();++i){
            cur_sum=cur_sum+nums[i];
            //需要提前判断，以防止我们的答案最小就为0
            //而不是数组中最大的负数
            if(max_sum<cur_sum){
                max_sum=cur_sum;
            }
            if(cur_sum<=0){
                cur_sum=0;
            }

        }
        return max_sum;
    }
};
// @lc code=end

