/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* myhead=new ListNode(0);
        ListNode* cur=myhead;
        map<int,int>mymap;
        vector<int>insert_order;
        for(auto ptr=head;ptr!=NULL;ptr=ptr->next){
            if(++(mymap[ptr->val])==1){
                insert_order.push_back(ptr->val);
            }
            
        }
        for(auto const & a:insert_order){
            if(mymap[a]==1){
                ListNode*new_node=new ListNode(a);
                cur->next=new_node;
                cur=cur->next;
            }
        }
        
        // for(auto const &a:mymap){
        //     if(a.second==1){
        //         ListNode*new_node=new ListNode(a.first);
        //         cur->next=new_node;
        //         cur=cur->next;
        //     }
        // }
        return myhead->next;
    }
};

