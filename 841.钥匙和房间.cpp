/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
//深度优先遍历
//先从0号房间进入，看其中的钥匙能开哪些房间
//如果这些房间还未访问过，就访问他们
//否则就返回
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int room_size = rooms.size();
        set<int> room_visited;
        dfs(rooms,room_visited,0);
        // cout<<room_visited.size()<<endl;
        if (room_visited.size()==room_size)
            return true;
        return false;
        
    }
    void dfs(vector<vector<int>> &rooms,set<int>&room_visited,int room_id)
    {
        //没进过的房间直接加到set里
        room_visited.insert(room_id);
        // cout<<room_id<<endl;
        // int room_size = rooms.size();
        for(auto key:rooms[room_id]){
            //如果钥匙号不在set里代表没进过这个房间
            if(room_visited.find(key)==room_visited.end()){
                //那么深度优先，进去这个房间
                dfs(rooms,room_visited,key);
            }
            //否则返回
        }
    }
};
// @lc code=end
