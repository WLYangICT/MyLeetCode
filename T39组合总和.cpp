/*
这题我采用比较简单的递归法
按照题目所给的例子，candidates=[2,3,6,7]，target=7
显然有2+2+3=7是一个方案
那么我们可以注意到，实际上使用了一个2之后，target剩下5，那么5也一定是可以由candidates组合而成的
如果我们对5进行combinationSum，再对所有结果加一个2，显然就能得到7的combinationSum
所以很自然地会想到递归

那么递归的终止条件呢，最终肯定是逐渐把target降下来，直到candidates的元素≥target

所以就可以直接写递归了：
首先，对于target，我们遍历每一个candidate：
    如果candidates[i] > target，那么显然不会被列入答案，直接排除
    如果candidates == target，单独作为一个答案加入ans
    如果candidates[i] < target，那么就可以用target - candidates[i]去递归，然后所有组合结果加上candidates[i]

但是但是！你以为这样就好了吗？当然是没有了，这样会出现重复结果：
    比如对于元素2，我们会用5去递归，得到2,3组合
    对于元素3，我们会用4去递归，得到2，2组合
    2，2，3这种组合重复了

    所以，需要去重
    这里用的去重手法也很暴力，ans里面所有组合，全部排序一遍
    如果重复的肯定是==，vector提供==实现，完全相同就是相同
    不同顺序的相同解排序之后肯定相同

    这样去重之后就AC了。

    当然，这样考虑了很多重复解，又在去重上暴力地花了很多时间，所以复杂度很垃圾
    但是确实一种可以AC的笨办法。
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        for(int i = 0; i < candidates.size(); i++)  //逐个取出元素
        {
            if(candidates[i] > target)  //已经超过target了，肯定不会使用
            {
                continue;
            }
            else if(candidates[i] == target)  //相等本身就是一个选项
            {
                vector<int> temp;
                temp.push_back(candidates[i]);
                ans.push_back(temp);
            }
            else  //candidates[i] < target，有戏
            {
                //分解、递归
                vector<vector<int>> temp;
                temp = combinationSum(candidates, target-candidates[i]);
                if(temp.size() == 0)  //分解之后没有解，说明这个candidates也用不上
                {
                    continue;
                }
                else
                {
                    //有方案
                    for (int j = 0; j < temp.size(); j++)  //每个方案取出来，加上当前的candidates，再放到ans里面
                    {
                        temp[j].push_back(candidates[i]);
                        ans.push_back(temp[j]);
                    } 
                }
            }
        }
        //这样能找出组合，但是必须要去重，全部sort一遍，然后去重
        vector<vector<int>> res;
        for (int i = 0; i < ans.size(); i++)
        {
            sort(ans[i].begin(), ans[i].end());
            int flag = false;
            for (int j = 0; j < res.size(); j++)
            {
                if (res[j] == ans[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};