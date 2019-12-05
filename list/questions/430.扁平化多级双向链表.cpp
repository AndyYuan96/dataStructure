/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        stack<Node*> nodes;
        nodes.push(head);

        Node *pre_node = NULL;

        while(!nodes.empty())
        {
            Node *cur_node = nodes.top();
            nodes.pop();

            if(cur_node->next)
            {
                nodes.push(cur_node->next);
            }

            if(cur_node->child)
            {
                nodes.push(cur_node->child);
                cur_node->child = NULL;
            }

            if(pre_node)
            {
                pre_node->next = cur_node;
                cur_node->prev = pre_node;
            }
            
            pre_node = cur_node;
        }
        return head;
    }
};
// @lc code=end


