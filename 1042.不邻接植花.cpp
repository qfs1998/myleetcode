/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>graph(N+1);
        for(auto path:paths){
            int x=path[0];
            int y=path[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int>res(N+1,0);
        for(int i=1;i<N+1;++i){
            vector<bool>used(5,false);
            for(auto a:graph[i]){
                used[res[a]]=true;
            }
            for(int j =1;j<5;++j){
                if(!used[j])
                    res[i]=j;
            }
        }
        res=vector<int>(res.begin()+1,res.end());
        return res;


    }
};
// @lc code=end

