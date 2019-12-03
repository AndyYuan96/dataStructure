/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
         
        if(!head || !head->next)
            return head;
        
        ListNode *cur_node = head->next;
        head->next = NULL;

        while(cur_node)
        {
            ListNode *next_node = cur_node->next;

            cur_node->next = head;
            head = cur_node;

            cur_node = next_node;
        }

        return head;
    }
};
// @lc code=end


