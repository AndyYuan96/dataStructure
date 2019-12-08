/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    vector<int> my_queue;
    int start;
    int end;
    int queue_size;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        my_queue.resize(k);
        start = -1;
        end = -1;
        queue_size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(start < 0)
        {
            start = 0;
            end = 0;
            my_queue[start] = value;
            return true;
        }

        if(end > start)
        {
            if(end - start + 1 == queue_size)
            {
                return false;
            }
            else
            {
                end = (end + 1) % queue_size;
                my_queue[end] = value;
                return true;
            }
            
        }
        else if(end < start)
        {
            if(start - end == 1)
            {
                return false;
            }
            else
            {
                end = end + 1;
                my_queue[end] = value;
                return true;
            }
        }
        else
        {
            end = (end + 1) % queue_size;
            my_queue[end] = value;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(start < 0)
            return false;
        
        if(start == end)
        {
            start = -1;
            end = -1;
            return true;
        }
        else
        {
            start = (start + 1) % queue_size;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return my_queue[start];
        }
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return my_queue[end];
        }
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(start < 0)
            return true;
        else
        {
            return false;
        }
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(start < end)
        {
            return (end - start + 1) == queue_size;
        }
        else if (start > end)
        {
            return (start - end) == 1;
        }
        else
        {
            if(start < 0)
            {
                return false;
            }
            else
            {
                return queue_size == 0;
            }
            
        }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    vector<int> my_queue;
    int start;
    int end;
    int queue_size;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        my_queue.resize(k);
        start = -1;
        end = -1;
        queue_size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }

        if(isEmpty())
        {
            start = 0;
        }
        end = (end + 1) % queue_size;
        my_queue[end] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(start == end)
        {
            start = -1;
            end = -1;
            return true;
        }
        else
        {
            start = (start + 1) % queue_size;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return my_queue[start];
        }
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return my_queue[end];
        }
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(start < 0)
            return true;
        else
        {
            return false;
        }
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(start < end)
        {
            return (end - start + 1) == queue_size;
        }
        else if (start > end)
        {
            return (start - end) == 1;
        }
        else
        {
            if(start < 0)
            {
                return false;
            }
            else
            {
                return queue_size == 0;
            }
            
        }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end


