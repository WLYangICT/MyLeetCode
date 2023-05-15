/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using std:: find;
using std:: vector;
class Solution {
public:
    /* 暴力方法，直接看地址有没有出现过，没有就记下来
    时间复杂度O(n^2)，空间复杂度O(n)
    bool hasCycle(ListNode *head) {
        vector<ListNode*> addr;  //存放已经经历过的地址
        ListNode* p = head;
        while(p != NULL)
        {
            if(find(addr.begin(), addr.end(), p) != addr.end())
            {
                //如果已经存在说明有环
                return true;
            }
            else
            {
                addr.push_back(p);
            }
            p = p->next;
        }
        return false;
    }
    */

    /*
    这种技巧其实我在相交链表那边就想用了
    本质上就是，因为节点的val不重要，我们关心的是地址是否成环或者相交
    节点上面是什么值并不重要
    所以我们可以用节点的val作为标记，我们是否走过
    但是相交链表那道题他不允许修改链表，所以不能用
    但是这道题没说
    而且有个很好的性质，|val| <= 1e5
    我们直接遍历链表，遇到值先判断val > 1e5，如果不是，我们把它修改成1e5+1
    如果超过，说明我们来过了
    那就成环了
    因此时间复杂度O(n)，空间复杂度O(1)
    */
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        while(p != NULL)
        {
            if(p->val == 100001)
            {
                return true;
            }
            else
            {
                p->val = 100001;
            }
            p = p->next;
        }
        return false;
    }
};