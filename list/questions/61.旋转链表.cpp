/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || !k)
            return head;
        
        ListNode *fast = head;
        ListNode *slow = head;
        int tmp = k;
        while(tmp > 0 && fast)
        {
            fast = fast->next;
            tmp--;
        }

        // 跳出循环情况
        // 1. tmp != 0, fast = null
        // 2. tmp = 0, fast != null
        // 3. tmp = 0, fast = null

        if(tmp)
        {
            int list_len = k - tmp;
            int new_move = k % list_len;
            // 如果需要移动，如果不需要移动直接返回head.
            if(new_move)
            {
                fast = head;
                while(new_move)
                {
                    fast = fast->next;
                    new_move--;
                }
            }
            else
            {
                return head;
            }
        }
        else
        {
            if(!fast)
                return head;
        }
        

        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *new_head = slow->next;
        slow->next = NULL;
        fast->next = head;

        return new_head;
    }
};
// @lc code=end


