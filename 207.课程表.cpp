/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
//拓扑排序
// 拓扑排序实际上应用的是贪心算法。贪心算法简而言之：每一步最优，全局就最优。
// 具体到拓扑排序，每一次都从图中删除没有前驱的顶点，这里并不需要真正的做删除操作，我们可以设置一个入度数组，每一轮都输出入度为 00 的结点，并移除它、修改它指向的结点的入度（-1−1即可），依次得到的结点序列就是拓扑排序的结点序列。如果图中还有结点没有被移除，则说明“不能完成所有课程的学习”。
// 拓扑排序保证了每个活动（在这题中是“课程”）的所有前驱活动都排在该活动的前面，并且可以完成所有活动。拓扑排序的结果不唯一。拓扑排序还可以用于检测一个有向图是否有环。相关的概念还有 AOV 网，这里就不展开了。
// https://www.bilibili.com/video/av17399461?from=search&seid=15668478565829599963
//https://leetcode-cn.com/problems/course-schedule/solution/tuo-bu-pai-xu-by-liweiwei1419/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses<=0)
            return true;
        
        vector<int>inDegree(numCourses,0);
        //入度数组。记录每个课的入度(先修课的总数)
        for(auto a:prerequisites){
            inDegree[a[0]]++;
        }
        //队列用于存放入度为0的课程
        queue<int>myqueue;
        //用于存放结果的数组，每个度数为0的节点出队后存入res数组
        vector<int>res;
        //初始化队列
        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0){
                myqueue.push(i);
            }
        }
        
        //开始出队
        while(!myqueue.empty()){
            
            int front=myqueue.front();
            myqueue.pop();
            res.push_back(front);
            for(auto a:prerequisites){
                //如果该课程的先修课是front，因为front被从图中删除了
                //所以该课程的入度-1
                if(a[1]==front){
                    --inDegree[a[0]];
                    //原先有一个错误就是把这个if放在上面这个if外面了，
                    //这样会无限循环，因为有一些节点本身就没有入度，本来就在队列中了
                    //需要在减去1度的情况下，考虑以下的情况
                    if(inDegree[a[0]]==0)
                        myqueue.push(a[0]);
                }
            }
        }

        return res.size()==numCourses;


    }
};
// @lc code=end

