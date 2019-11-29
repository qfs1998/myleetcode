/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //answer is dp[0][N-1]>0
        int N=piles.size();
        int dp[N][N];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;++i)
            dp[i][i]=piles[i];

        for(int i=N-2;i>=0;--i)
        {
            for(int j=i+1;j<N;++j)
            {
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][N-1]>0;
    }
};



// @lc code=end

