/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start



class MyLinkedList {
public:
    ListNode* _head;

    /** Initialize your data structure here. */
    MyLinkedList() {
        _head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *cur_node = _head;
        int cur_index = 0;
        while(cur_node)
        {
            if(cur_index == index)
                return cur_node->val;

            cur_node = cur_node->next;
            cur_index++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* new_head = new ListNode(val);
        if(_head)
        {
            new_head->next = _head;
            _head = new_head;
        }
        else
        {
            _head = new_head;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        ListNode *cur_node = _head;
        if(!cur_node)
        {
            ListNode *new_tail = new ListNode(val);
            _head = new_tail;
        }
        else
        {
            while(cur_node->next)
            {
                cur_node = cur_node->next;
            }

            cur_node->next = new ListNode(val);
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0)
        {
            addAtHead(val);
        }
        else
        {
            int cur_index = 0;
            int target_index = index - 1;
            ListNode *cur_node = _head;

            while(cur_index < target_index && (cur_node))
            {
                cur_index++;
                cur_node = cur_node->next;
            }

            if(cur_index == target_index && (cur_node))
            {
                if(cur_node->next)
                {
                    ListNode *added_node = new ListNode(val);
                    added_node->next = cur_node->next;
                    cur_node->next = added_node;
                }
                else
                {
                    cur_node->next = new ListNode(val);
                }
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0)
            return;
        else if(index == 0)
        {
            if(_head->next)
            {
                _head = _head->next;
            }
            else
            {
                _head = NULL;
            }
        }
        else
        {
            int cur_index = 0;
            int target_index = index - 1;
            ListNode *cur_node = _head;
            while(cur_index < target_index && cur_node)
            {
                cur_index++;
                cur_node = cur_node->next;
            }
            if(cur_index == target_index && cur_node)
            {
                if(cur_node->next)
                {
                    cur_node->next = cur_node->next->next;   
                }
            }   
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end


