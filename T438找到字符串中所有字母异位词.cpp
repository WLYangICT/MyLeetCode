/*
这道题是一道经典的滑动窗口题
我们同样还是从暴力的解法来入手：
    在s当中，遍历与p相同大小的子串只需要O(n)的时间复杂度
    这里的遍历方法我最开始采用的方法特别傻：
        我把i从0到s.size()-p.size()进行遍历，然后再从i到i+p.size()进行字符叠加获得子串
    而对于每个子串，我们需要判断其是否为p的异位词：
        其实就是各个字母出现的次数是否相同
        这里我刚开始采用map进行实现，并通过map判断是否相等

其实大体思路是没错的：滑动窗口获取子串，通过字母出现次数判断是否为异位词
但是我在第一遍实现的时候进行了太多的重复操作以及map的特性问题导致了无法AC

首先滑动窗口的遍历是可以化简的：
    设窗口左右index为left和right
    当right - left < p.size() - 1时，
    只需要单方面增加right就行
    当中right - left == p.size() - 1时，
    后续增加right的同时也需要增加left
    这样才是真正的用O(n)的时间进行窗口的遍历，前面是O(m*n)

窗口是简单地滑动向前，那么实际上map存储的信息也只需要根据左右修改的单个符号进行修改，而不是每次都重新取
对于左边去掉的部分，其次数--，对于右边增强的部分，次数++
始终保持维护一个map

看起来似乎没问题了，但是这里发现了使用map的一个隐患！！！
比如说p = "abc"，mp={'a':1, 'b':1, 'c':1}
对于没有出现过的字符，是不存在的，但是如果你去访问mp['e']或者执行mp['e']++，map会先初始化'e':0

但问题就在于，假如出现过e，后来e又去掉了，就会留下'e': 0，这和没出现过'e'是不一样的，至少用map判断是不等的

因此最后选择用vector<int>，直接开大小为26的数组代表26的字母的次数，用vector判断相等，于是AC
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size())
        {
            return ans;
        }
        vector<int> mq(26);
        vector<int> mp(26);
        for(int i = 0; i < p.size(); i++)
        {
            mp[p[i] - 'a']++;
        }
        int left = 0, right = 0;
        while(right < s.size())
        {
            //既然纳入了窗口
            mq[s[right] - 'a']++;

            if((right -left) == (p.size() - 1))
            {
                //已经大小匹配了，可以看看字典是否相等
                if(mq == mp)
                {
                    ans.push_back(left);
                }
                //不管是否相等，都要移动
                if(right < (s.size() - 1))
                {
                    right++;
                    mq[s[left] - 'a']--;
                    left++;
                }
                else
                {
                    break;
                }
            }
            if((right - left) < (p.size() - 1))
            {
                if(right < (s.size() - 1))
                {
                    //left不动，right右移
                    right++;
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