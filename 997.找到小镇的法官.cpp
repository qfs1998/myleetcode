/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1)
            return 1;
        //in-out = N-1
        vector<int>g(N+1,0);
        
        for(auto const&a:trust){
            g[a[1]]++;
            g[a[0]]--;
        }
        int sum=0;
        int pos=-1;
        for(int i=0;i<N+1;++i){
            if(g[i]==N-1){
                sum++;
                pos=i;
            }
        }
        if(sum==1)
            return pos;
        else 
            return -1;
    }
};
// @lc code=end

