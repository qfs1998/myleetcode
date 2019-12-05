/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min_price=INT_MAX;
        int max_earn=INT_MIN;
        for(int i=0;i<prices.size();++i){
            if(cur_min_price>prices[i])
                cur_min_price=prices[i];
            int diff=prices[i]-cur_min_price;
            max_earn=max_earn>diff?max_earn:diff;
        }
        max_earn=max_earn<0?0:max_earn;
        return max_earn;

    }
};
// @lc code=end

