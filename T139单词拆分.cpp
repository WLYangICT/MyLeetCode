/*
想到一个简单的办法就是逐位往后读，每一次都判断一下当前累计的字符串是不是出现在字典里面的单词
比如识别leetcode：
    l->le->lee->leet  识别成功
    c->o->d->e  识别成功
这样一次遍历似乎就能判断，时间复杂度是O(length * word_num * word_length)，感觉还是蛮费时的
不过这个方法其实是错的，主要在于它会急于求成的判断（贪心）
比如s = "aaaaaaa" wordDist = ["aaa", "aaaa"]
识别过程:
    a->aa->aaa  识别成功
    a->aa->aaa  再次识别成功
    a  识别失败
得到答案：无法组成
实际答案：可以由"aaa"和"aaaa"组成
这边的问题就在贪心了
class Solution {
public:
    bool if_in_dict(string s, vector<string>& wordDict)
    {
        for(int i = 0; i < wordDict.size(); i++)
        {
            if(s == wordDict[i])
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool* dp = new bool [s.length() + 1];  //dp[i]表示字符串s的1~i位子串是否由字典构成
        dp[0] = 1;
        string tmp;
        bool reflag = 1;  //tmp是否设为空串，重新累积
        int front_index = 0;  //1~front_index位可以被构成
        for(int i = 0; i < s.length(); i++)
        {
            if(reflag)
            {
                tmp = "";
            }
            tmp += s[i];
            if(if_in_dict(tmp, wordDict))
            {
                reflag = 1;
                front_index = i + 1;
            }
            else
            {
                reflag = 0;
            }
        }
        if(front_index == s.length())
        {
            return true;
        }
        return false;
    }
};
*/

/*
一开始把这道题想成了背包类问题：
    以为字符串s是目标，wordDict是备选集合，但是这个思路其实很怪，没能够想下去
    ps：感觉也不是不能做

后来看了题解发现这其实是分段最小二乘法那类的题目，解法的标志是i、j双指针：
    我们还是按照DP的惯用思想：从后向前分析
    解的结构是：dp[i]表示从1~i位的子串是否能用wordDict组成（0/1）
    我们求dp[i]的时候，保持i的位置不动，用一个指针j逐位向前探索：
        如果dp[i] = true的话，一定会存在一个位置j，s[j:i]是wordDict的一个字符串，且dp[j] = true
        如果指针j走到头都没找到这样的位置的话，那么1~i就不满足条件
    最后返回dp[s.length()]即可

时间复杂度应该是O(s.length * word.length * word_num)相比从头逐位向后，并没有更快，但是不贪心、综合考虑
从而能够得到正确的解
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        bool* dp = new bool [s.length() + 1];  //dp[i]表示字符串s的1~i位子串是否由字典构成
        dp[0] = 1;
        set<string> Dict(wordDict.begin(), wordDict.end());
        bool flag = false;
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(Dict.find(s.substr(j, i-j+1)) != Dict.end() && dp[j])
                {
                    dp[i+1] = true;
                    flag = true;
                    break; 
                }
                else
                {
                    flag = false;
                }
            }
            if(!flag)
            {
                dp[i+1] = 0;
            }
        }
        return dp[s.length()];
    }
};