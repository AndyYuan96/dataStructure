/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    stack<int> sk;
    stack<int> min_sk;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        sk.push(x);
        if(!min_sk.empty())
        {
            if(x < min_sk.top())
            {
                min_sk.push(x);
            }
            else
            {
                min_sk.push(min_sk.top());
            }
        }
        else
        {
            min_sk.push(x);
        }
        
    }
    
    void pop() {
        if(!sk.empty())
        {
            sk.pop();
            min_sk.pop();
        }
    }
    
    int top() {
        if(!sk.empty())
            return sk.top();
        else
        {
            return -1;
        }
        
    }
    
    int getMin() {
        return min_sk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


