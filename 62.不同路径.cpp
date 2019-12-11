/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
//排列组合 C(m-1+n-1,n-1) =C(m+n-2,n-1)
//溢出，阶乘的值太大了，基本类型存不下
// class Solution {
// public:
//     long long uniquePaths(long long m, long long n) {
//         long long res = (factorial(m+n-2)/factorial(m-1))/factorial(n-1);
//         return res;
//     }
//     long long factorial(long long num){
//         long long res=1;
//         while(num){
//             res=res*num;
//             --num;
//         }
//         return res;
//     }
// };

//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
            return 1;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;++i)
            dp[0][i]=1;
        for(int i=0;i<m;++i)
            dp[i][0]=1;
        for(int i=1;i<m;++i)
            for(int j=1;j<n;++j)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];

        return dp[m-1][n-1];    
    }
};
// @lc code=end
