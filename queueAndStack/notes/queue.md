# queue

​	先入先出（FIFO）。

​		

```
C++函数：
	queue<int> q;
	q.push(2);
	q.empty();
	q.pop();
	q.front();
	q.back();
	q.size();
```



```
广度优先搜索：找出从根节点到目标节点的最短路径
	新添加的节点不会立即遍历，而是在下一轮中处理。
	当前时刻新添加的是下一时刻的Node, 当下一时刻遇到该node时返回的也是下一时刻的step.
	queue<Node> que;
	int step = 0;
	que.push(head);
	
	while(!que.empty())
	{
        step = step+1;
        int size = que.size();
        for(int i = 0; i < size; i++)
        {
            Node cur = que.front();
            if(cur == target)
            	return step;
            for(Node next : the neighbors of cur)
            {
                add next to queue;
            }
            que.pop();
        }
	}
	
```

