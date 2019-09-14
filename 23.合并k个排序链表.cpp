/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int>mymap;
        ListNode * head=new ListNode(0);
        ListNode*cur=head;
        for(auto  node:lists){
            for(;node;node=node->next){
                mymap[node->val]++;
            }
        }
        for(auto const&item:mymap){
            for(int i=item.second;i>0;--i){
                cur->next=new ListNode(item.first);
                cur=cur->next;
            }
        }
        return head->next;
    }
};
