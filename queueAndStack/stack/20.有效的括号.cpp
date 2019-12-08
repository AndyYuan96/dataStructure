/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        
        int size = s.size();
        if(size == 0)
            return true;
        stack<char> sk;
        sk.push(s[0]);

        for(int i = 1; i < size; i++)
        {
            if(sk.empty())
            {
                sk.push(s[i]);
            }
            else
            {
                if(judgeKuoHao(sk.top(),s[i]))
                {
                    sk.pop();
                }
                else
                {
                    sk.push(s[i]);
                }
            }
        }

        return sk.empty();
    }

    bool judgeKuoHao(char s1, char s2)
    {
        if(s1 == '(')
        {
            return s2 == ')';
        }
        else if(s1 == '{')
        {
            return s2 == '}';
        }
        else if(s1 == '[')
        {
            return s2 == ']';
        }

        return false;
    }
};
// @lc code=end


