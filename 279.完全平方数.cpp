/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
/*动态规划*/
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int>f(n+1,n);
//         f[0]=0;
//         for(int i=1;i<=n;++i)
//         {
//             for(int j=1;j*j<=i;++j)
//             {
//                 f[i]=min(f[i],f[i-j*j]+1);
//             }
//         }
//         return f[n];
//     }
// };

/*
最小，最少，BFS 
*/
class Solution {
public:
    int numSquares(int n) {
        
    }
};

