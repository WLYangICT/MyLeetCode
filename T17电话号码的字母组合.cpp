//写完扫了一眼题解，似乎都是用递归、回溯，这样看来我的解法似乎不太一样，有空写个题解
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<vector<char>> dict;
        for(int i = 0; i < len; i++)
        {
            switch(digits[i])
            {
                case '2':
                    dict.push_back({'a', 'b', 'c'});
                    break;
                case '3':
                    dict.push_back({'d', 'e', 'f'});
                    break;
                case '4':
                    dict.push_back({'g', 'h', 'i'});
                    break;
                case '5':
                    dict.push_back({'j', 'k', 'l'});
                    break;
                case '6':
                    dict.push_back({'m', 'n', 'o'});
                    break;
                case '7':
                    dict.push_back({'p', 'q', 'r', 's'});
                    break;
                case '8':
                    dict.push_back({'t', 'u', 'v'});
                    break;
                case '9':
                    dict.push_back({'w', 'x', 'y', 'z'});
                    break;
            }
        }
        int num;  //组合数目
        if(len == 0)
        {
            num = 0;
        }
        else
        {
            num = dict[0].size();
            for(int i = 1; i < dict.size(); i++)
            {
                num *= dict[i].size();
            }
        }

        //开始处理
        int deal_num = 0;
        vector<string> ans;
        int* flag = new int [len];
        int* ptr = new int [len];
        for(int i = 0; i < dict.size(); i++)
        {
            flag[i] = dict[i].size();
            ptr[i] = 0;
        }
        string s;
        while(deal_num < num)
        {
            s = "";
            for(int i=0;i<dict.size();i++)
            {
                s += dict[i][ptr[i]];
            }
            ans.push_back(s);
            //指针的挪动很重要
            ptr[dict.size()-1]++;
            for(int i = dict.size()-1; i>=0; i--)
            {
                if(ptr[i] > flag[i]-1)
                {
                    if(i > 0)
                    {
                        ptr[i-1]++;
                        ptr[i] = 0;
                    }
                    else
                    {
                        return ans;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};