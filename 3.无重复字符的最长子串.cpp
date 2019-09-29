/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>cur_set;
        int cur_len=0;
        int max_len=0;
        int left=0;
        for(int i=0;i<s.size();++i)
        {
            while(cur_set.find(s[i])!=cur_set.end())
            {
                cur_set.erase(s[left]);
                ++left;
            }
            cur_set.insert(s[i]);
            max_len=max_len>=i-left+1?max_len:i-left+1;
        }
        return max_len;
    }
};

