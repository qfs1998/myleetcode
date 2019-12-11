/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
public:
    long long uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        long long m = obstacleGrid.size();
        long long n = obstacleGrid[0].size();
        vector<vector<long long >> dp(m, vector<long long >(n, 0));
        //初始化 第一行和第一列如果没有障碍物就是1，否则就是0
        //我们dp[i][j]代表到(i,j)的最大路径数
        //因此0 就代表没有路可以到达这里
        // for(long long i=0;i<n;++i)
        //     if(obstacleGrid[0][i]==1)
        //         dp[0][i]=0;
        //     else
        //         dp[0][i]=1;
        // for(long long i=0;i<m;++i)
        //     if(obstacleGrid[i][0]==1)
        //         dp[i][0]=0;
        //     else
        //         dp[i][0]=1;
        //dp的过程
        for (long long i = 0; i < m; ++i)
        {
            for (long long j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
