/*
最近做题老是有一些奇怪的tricks，可能导致我避开了题目可能考察的知识点

题目给定一个二维数组intervals，里面是一堆的区间端点start[i] end[i]
现在要合并所有的重叠区间

我也不知道我的想法是怎么来的，就是突发奇想，直接说想法吧
维护一个答案二维数组ans，里面包含当前已遍历的所有不重合区间，初始为空
遍历intervals数组，对于里面的每个区间，有start和end
此时遍历ans，看看是否有可以合并的区间，如果有，就合并区间修改当前的start和end，并删除该区间
最后把修改后的start和end放进ans

看个例子
intervals = [[1,3],[2,6],[8,10],[15,18]]
ans = []

（1）获得[1, 3]，start=1，end=3
    ans为空，直接加入，ans=[[1, 3]]
（2）获得[2, 6]，start=2，end=6
    遍历ans：
        针对[1, 3]
        显然有重合，注意，将当前手握的[2, 6]融合[1, 3]为[1, 6]
        删除ans中的[1, 3]，加入[1, 6]
        ans = [[1, 6]]
（3）获得[8, 10], s=8，e=10
    遍历ans，没有重合
    直接加入ans，ans=[[1, 6], [8, 10]]
（4）最后是[15, 18]
    遍历ans，没有重合
    直接加入ans，ans=[[1, 6], [8, 10], [15, 18]]

这种办法的时间复杂度确实差点，是O(n^2)

而且一定要注意好区间重叠的判断以及区间的融合
*/

class Solution {
public:
    bool judge(int s1, int e1, int s2, int e2)
    {
        //判断[s1, e1]和[s2, e2]代表的区间是否重叠
        return ((s2 <= e1 && e1 <= e2) || (s2  <= s1 && s1 <= e2) || (s1 < s2 && e1 > e2));
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int start, end;
        for(int i = 0; i < intervals.size(); i++)
        {
            //遍历每一对数对
            start = intervals[i][0];
            end = intervals[i][1];
            for(int j = 0; j < ans.size(); j++)
            {
                //遍历所有已有的区间，看看也没有重叠
                if(judge(start, end, ans[j][0], ans[j][1]))  //有重叠
                {
                    //修改当前区间
                    if(ans[j][0] <= end && end <= ans[j][1])  //end在里面
                    {
                        end = ans[j][1];
                        if(start >= ans[j][0] && start <= ans[j][1])  //start也在里面
                        {
                            start = ans[j][0];
                        }
                    }
                    //end肯定不在里面了
                    else if(start >= ans[j][0] && start <= ans[j][1])  //start在里面
                    {
                        start = ans[j][0];
                    }
                    //start和end都在外面
                    else
                    {
                        //包含就不用动了
                    }
                    //删除ans里面被融合的区间
                    ans.erase(ans.begin()+j);
                    j--;  //跟着移动很重要
                }
            }
            //最后插入大融合的区间
            ans.push_back({start, end});
        }
        return ans;
    }
};