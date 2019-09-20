/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
        
//     }
// };

// class Solution {
// public:
//     vector<vector<int> > permute(vector<int> &num) {
//         vector<vector<int> > V;
//         sort(num.begin(),num.end());
//         do{
//             V.push_back(num);
//         }while(next_permutation(num.begin(),num.end()));
//         return V;
//     }
// };
class Solution {
public:
        vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> res;
        vector<bool>used(num.size(),false);
        vector<int>pre;
        dfs(num,res,pre,used,0);
        return res;
    }

private:
    void dfs(
    vector<int>&num,
    vector<vector<int>>&res,
    vector<int>&pre,
    vector<bool>used,
    int deep)
    {
        if(deep==num.size())
        {
            res.push_back(pre);
            return;
        }
        
        for(int i=0;i<num.size();++i)
        {
            if(used[i]==false)
            {
                pre.push_back(num[i]);
                used[i]=true;
                dfs(num,res,pre,used,deep+1);
                used[i]=false;
                pre.pop_back();
            }
        }
        return ;
    }

};

