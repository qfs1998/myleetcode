/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //vector<vector<int>>v(n,vector<int>(n,0));
        vector<vector<int>>v(n, vector<int>(n, 0));
        //border side
        int u=0;
        int d=n-1;
        int l=0;
        int r=n-1;
        int elem=1;
        while(true)
        {
            //go right
            for(int i=l;i<=r;++i)
                v[u][i]=elem++;
            if(++u>d)
                break;
            //go down
            for(int i=u;i<=d;++i)
                v[i][r]=elem++;
            if(--r<l)
                break;
            //go left
            for(int i=r;i>=l;--i)
                v[d][i]=elem++;
            if(--d<u)
                break;
            //go up
            for(int i=d;i>=u;--i)
                v[i][l]=elem++;
            if(++l>r)
                break;
        }
        return v;
    }
};
