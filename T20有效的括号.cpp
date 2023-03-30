class Solution {
public:
    bool isValid(string s) {
        //括号用栈匹配就完事了
        stack<char> sta;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
            {
                sta.push(s[i]);
            }
            else
            {
                if(sta.empty())
                {
                    return false;
                }
                if (s[i] == ')')
                {
                    if (sta.top() != '(')
                    {
                        return false;
                    }
                    else
                    {
                        sta.pop();
                    }
                }
                else if (s[i] == '}')
                {
                    if (sta.top() != '{')
                    {
                        return false;
                    }
                    else
                    {
                        sta.pop();
                    }
                }
                else if (s[i] == ']')
                {
                    if (sta.top() != '[')
                    {
                        return false;
                    }
                    else
                    {
                        sta.pop();
                    }
                }
            }
        }
        if (sta.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};