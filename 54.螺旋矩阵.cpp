/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.empty())
            return ans;
        int u=0;
        int d=matrix.size()-1;
        int l=0;
        int r=matrix[0].size()-1;
        while(true)
        {
            //go right
            for(int i=l;i<=r;++i)
                ans.push_back(matrix[u][i]);
            if(++u>d)
                break;
            //go down
            for(int i=u;i<=d;++i)
                ans.push_back(matrix[i][r]);
            if(--r<l)
                break;
            //go left
            for(int i=r;i>=l;--i)
                ans.push_back(matrix[d][i]);
            if(--d<u)
                break;
            //go up
            for(int i=d;i>=u;--i)
                ans.push_back(matrix[i][l]);
            if(++l>r)
                break;
        }
        return ans;
    }
};


