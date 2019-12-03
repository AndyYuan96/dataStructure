app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jinwei = 0;

        ListNode *ret = NULL;
        ListNode *cur_node = ret;

        while(l1 && l2)
        {
            int cur_sum = l1->val + l2->val + jinwei;
            ListNode *tmp_node = new ListNode(cur_sum % 10);
            jinwei = cur_sum / 10;

            if(!cur_node)
            {
                cur_node = tmp_node;
                ret = tmp_node;
            }
            else
            {
                cur_node->next = tmp_node;
                cur_node = cur_node->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int cur_sum = l1->val + jinwei;
            ListNode *tmp_node = new ListNode(cur_sum % 10);
            jinwei = cur_sum / 10;

             if(!cur_node)
            {
                cur_node = tmp_node;
                ret = tmp_node;
            }
            else
            {
                cur_node->next = tmp_node;
                cur_node = cur_node->next;
            }

            l1 = l1->next;
        }

        while(l2)
        {
            int cur_sum = l2->val + jinwei;
            ListNode *tmp_node = new ListNode(cur_sum % 10);
            jinwei = cur_sum / 10;
            
             if(!cur_node)
            {
                cur_node = tmp_node;
                ret = tmp_node;
            }
            else
            {
                cur_node->next = tmp_node;
                cur_node = cur_node->next;
            }

            l2 = l2->next;
        }

        if(jinwei)
        {
            cur_node->next = new ListNode(jinwei);
        }

        return ret;
    }
};
// @lc code=end


