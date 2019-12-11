/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int size = row.size();
        int count=0;
        for (int i = 0; i < size - 1; i = i + 2)
        {
            int lover = row[i] ^ 1;
            if (row[i + 1] != lover)
            {
                ++count;
                auto it = find(row.begin(),row.end(),lover);
                *it = row[i + 1];
                row[i + 1] = lover;
            }
        }
        return count;
    }
};
// @lc code=end
