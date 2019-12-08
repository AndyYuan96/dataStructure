/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        
        int step = 0;
        queue<int> que;

        que.push(n);

        while(!que.empty())
        {
            int size = que.size();
            step++;
            for(int i = 0; i < size; i++)
            {
                int top = que.front();
                que.pop();
                int max_squre = sqrt(top);

                for(int j = max_squre; j > 0; j--)
                {
                    int next_tmp = top - j * j;
                    if(!next_tmp)
                    {
                        return step;
                    }
                    que.push(next_tmp);
                }
            }
        }

        return -1;
    }
};
// @lc code=end


