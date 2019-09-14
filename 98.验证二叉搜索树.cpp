/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void mid_order(TreeNode*root){
        if(root==NULL)
            return;
        mid_order(root->left);
        v.push_back(root->val);
        mid_order(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        mid_order(root);
        vector<int>v2(v);
        sort(v2.begin(),v2.end());
        auto it= unique(v2.begin(),v2.end());
        if(it!=v2.end())
            return false;
        if(v2==v)
            return true;
        else
            return false;
    }
};

