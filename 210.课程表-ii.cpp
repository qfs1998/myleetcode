/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        for(auto a:prerequisites)
            ++inDegree[a[0]];
        
        queue<int>myqueue;
        for(int i=0;i<inDegree.size();++i){
            if(inDegree[i]==0)
                myqueue.push(i);
        }

        vector<int>res;
        while(!myqueue.empty()){
            int front=myqueue.front();
            myqueue.pop();
            res.push_back(front);
            for(auto a:prerequisites){
                if(a[1]==front){
                    --inDegree[a[0]];
                    if(inDegree[a[0]]==0)
                        myqueue.push(a[0]);
                }
            }
        }
        if (res.size()==numCourses)
            return res;
        else
            return vector<int>(); 
    }
};
// @lc code=end

