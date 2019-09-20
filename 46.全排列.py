#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums)==0:
            return []
        res=[]
        used=[False]*len(nums)
        self.__dfs(nums,res,[],used,0)
        return res
    def __dfs(self,nums:[],res:[],pre:[],used:[],deep:int):
        if deep==len(nums):
            res.append(pre.copy())
            return
        
        for i in range(len(nums)):
            if not used[i]:
                pre.append(nums[i])
                used[i]=True
                self.__dfs(nums,res,pre,used,deep+1)
                used[i]=False
                pre.pop()

