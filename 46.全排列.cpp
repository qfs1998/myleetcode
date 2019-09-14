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
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > V;
        sort(num.begin(),num.end(),[](const int&a,const int &b){return a>b;});
        do{
            V.push_back(num);
        }
        while(prev_permutation(num.begin(),num.end()));
        return V;
    }
};

