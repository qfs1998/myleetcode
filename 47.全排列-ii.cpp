/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>v;
//         do{
//             v.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));
//         return v;
//     }
// };


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums,0);
        return res;
        
    }
private:
    vector<vector<int>>res;
    

    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    bool isRepeat(vector<int>&nums,int first,int i)
    {
        int temp=nums[i];
        for(int j=first;j<i;++j)
            if(nums[j]==temp)
                return true;
        return false;
    }
    void dfs(vector<int>&nums,int first)
    {
        if(first==nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i=first;i<nums.size();++i)
        {
            //剪枝
            //同一层重复了
            if(isRepeat(nums,first,i))
                continue;
            //swap the i-th element to the first-th place
            swap(nums[first],nums[i]);
            dfs(nums,first+1);
            //reset the status
            swap(nums[first],nums[i]);
        }
    }

};
