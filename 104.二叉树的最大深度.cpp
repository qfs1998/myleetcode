/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//1.递归dfs recursive
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root)
//             return 0;
//         return 1+max(maxDepth(root->left),maxDepth(root->right));
//     }
// };

//2.stack dfs
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root)
//             return 0;
//         stack<pair<TreeNode*,int>>mystack;
//         TreeNode* p=root;
//         int maxdeep=0;
//         int deep=0;
//         while(!mystack.empty()||p!=NULL){
//             while(p){
//                 mystack.push(make_pair(p,++deep));
//                 p=p->left;
//             }
//             //出入栈的时候不要想象叶子节点，
//             //可以想象一下叶子节点的父母应该如何操作
//             p=mystack.top().first;
//             deep=mystack.top().second;
//             if(maxdeep<deep)
//                 maxdeep=deep;
//             p=p->right;
            
//             mystack.pop();
//         }
//         return maxdeep;

//     }
// };

//3.bfs queue
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        int deep=0;
        while(!myqueue.empty()){
            // 本层的节点个数
            //用nums这样就不用构造pair来记住每个节点的深度了
            int nums=myqueue.size();
            ++deep;
            for(int i=0;i<nums;++i){
                TreeNode*p=myqueue.front();
                if(p->left)myqueue.push(p->left);
                if(p->right)myqueue.push(p->right);
                myqueue.pop();
            }
        }
        return deep;

    }
};
// @lc code=end

