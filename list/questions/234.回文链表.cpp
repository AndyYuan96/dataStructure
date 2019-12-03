/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        // 先中点，后反转

        if(!head || !head->next)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the last

        ListNode *reverse_head = NULL;
        
        while(slow)
        {
            ListNode *next_node = slow->next;
            slow->next = reverse_head;
            reverse_head = slow;
            slow = next_node;   
        }
        
        while(head && reverse_head)
        {
            if(head->val != reverse_head->val)
                return false;

            head = head->next;
            reverse_head = reverse_head->next;
        }

        return true;
    }
};
// @lc code=end


