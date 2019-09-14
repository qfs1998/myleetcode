/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int max_index=0;
        int max_height=0;
        int water=0;
        int second_max;
        //找柱子高度最大值
        for(int i=0;i<height.size();++i)
        {
            if(height[i]>max_height)
            {
                max_index=i;
                max_height=height[i];
            }
        }
        //计算左边
        second_max=height[0];
        for(int i=0;i<max_index;++i)
        {
            if(height[i]>second_max)
                second_max=height[i];
            water=water+second_max-height[i];
        }
        //计算右边
        second_max=height[height.size()-1];
        for(int i=height.size()-1;i>max_index;--i)
        {
            if(height[i]>second_max)
                second_max=height[i];
            water=water+second_max-height[i];
        }
        return water;
    }
};

