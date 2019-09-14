/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *myhead=new ListNode(0);
        ListNode *cur=myhead;
        myhead->next=head;
        while(cur&&cur->next&&cur->next->next){
            ListNode* temp=cur->next->next;
            cur->next->next=temp->next;
            temp->next=cur->next;
            cur->next=temp;
            cur=cur->next->next;
        }
        return myhead->next;
    }
};

