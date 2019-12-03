/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *before_node = NULL;
        ListNode *cur_node = head;

        while(cur_node)
        {
            if(cur_node->val == val)
            {
                if(!before_node)
                {
                    head = head->next;
                }
                else
                {
                    before_node->next = cur_node->next;
                }
                cur_node = cur_node->next;
            }
            else
            {
                before_node = cur_node;
                cur_node = cur_node->next;
            }
        }

        return head;
    }
};
// @lc code=end


