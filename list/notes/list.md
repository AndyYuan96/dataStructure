![](..//pic/list.png)

单链表

双链表

```
struct node{
    int val;
    node* next;
    node(int x): val(x),next(NULL) {}
};

访问O(n)
插入O(1)
删除O(n): 需要找到当前节点的上一个节点O(n)
```

