/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//树的层次遍历 BFS 用队列来实现
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>myqueue;
        TreeNode*p=root;
        myqueue.push(p);
        int max_level=0;
        int cur_level=0;
        int max_sum=INT_MIN;
        while(!myqueue.empty()){
            int sum=myqueue.size();
            int cur_sum=0;
            ++cur_level;
            while(sum--){
                TreeNode*ptr=myqueue.front();
                myqueue.pop();
                if(ptr->left)
                    myqueue.push(ptr->left);
                if(ptr->right)
                    myqueue.push(ptr->right);
                cur_sum=cur_sum+ptr->val;
            }
            if(max_sum<cur_sum){
                max_sum=cur_sum;
                max_level=cur_level;
            }
        }
        return max_level;
    }
};
// @lc code=end

