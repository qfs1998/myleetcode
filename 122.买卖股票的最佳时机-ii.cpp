/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        if(prices.size()<=1)
            return profit;
        
        for(int i=0;i<prices.size()-1;++i){
            int diff=prices[i+1]-prices[i];
            if(diff>0)
                profit=profit+diff;
        }
        return profit;
    }
};
// @lc code=end

