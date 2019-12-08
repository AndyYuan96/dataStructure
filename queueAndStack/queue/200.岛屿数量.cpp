/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size())
            return 0;
        vector<bool> tmp(grid[0].size(),false);
        vector<vector<bool>> marks(grid.size(),tmp);

        int new_cols[4] = {-1,1,0,0};
        int new_rows[4] = {0,0,-1,1};

        int ret_count = 0;

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!marks[i][j] && grid[i][j] == '1')
                {
                    
                    queue<int> rows;
                    queue<int> cols;

                    rows.push(i);
                    cols.push(j);

                    marks[i][j] = true;
                    ret_count++;

                    while(!rows.empty())
                    {
                        int size = rows.size();

                        for(int k = 0; k < size; k++)
                        {
                            int cur_row = rows.front();
                            int cur_col = cols.front();

                            cols.pop();
                            rows.pop();

                            int new_col;
                            int new_row;
                            for(int m = 0; m < 4 ;m++)
                            {
                                new_col = cur_col + new_cols[m];
                                new_row = cur_row + new_rows[m];

                                if(new_row < 0 || new_row > grid.size()-1 || new_col < 0 || new_col > grid[0].size() - 1)
                                {
                                    continue;
                                }
                                else
                                {
                                    if(!marks[new_row][new_col] && grid[new_row][new_col] == '1')
                                    {
                                        cols.push(new_col);
                                        rows.push(new_row);
                                        marks[new_row][new_col] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        return ret_count;
    }
};
// @lc code=end


