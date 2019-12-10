/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
//动态规划
class Solution
{
public:
	void DpValueUpdate(const vector<vector<int>> &grip, vector<vector<int>> &dp)
	{
		int m = grip.size();
		int n = grip[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == 0 && j == 0)
					continue;
				int up = INT_MAX, left = INT_MAX;
				//上面没有
				if (i - 1 < 0 && j - 1 >= 0)
				{
					dp[i][j] = dp[i][j - 1] + grip[i][j];
					continue;
				}
				//左边没有
				if (i - 1 >= 0 && j - 1 < 0)
				{
					dp[i][j] = dp[i - 1][j] + grip[i][j];
					continue;
				}
				// if(m-1>=0)
				up = dp[i - 1][j] + grip[i][j];
				// if(n-1>=0)
				left = dp[i][j - 1] + grip[i][j];
				dp[i][j] = min(up, left);
			}
		}
	}
	int minPathSum(vector<vector<int>> &grip)
	{

		int m = grip.size();
		int n = grip[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grip[0][0];

		DpValueUpdate(grip, dp);
		// for (auto const&a : dp)
		// {
		// 	for (auto const&b : a)
		// 		cout << b << '\t';
		// 	cout << endl;
		// }
		return dp[m - 1][n - 1];
	}
};


