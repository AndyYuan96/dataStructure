/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *listA = headA;
        ListNode *listB = headB;

        int listALen = 0;
        int listBLen = 0;

        while(listA)
        {
            listALen++;
            listA = listA->next;
        }

        while(listB)
        {
            listBLen++;
            listB = listB->next;
        }

        int up = 0;

        if(!listBLen || !listALen)
            return NULL;
        
        listA = headA;
        listB = headB;

        if(listALen <= listBLen)
        {
            up = listBLen - listALen;
            while(up > 0)
            {
                listB = listB->next;
                up--;
            }
        }
        else
        {
            up = listALen - listBLen;
            while(up > 0)
            {
                listA = listA->next;
                up--;
            }

        }

        while(listA && listB)
        {
            if(listA == listB)
            {
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }

        return NULL;
    }
};
// @lc code=end


