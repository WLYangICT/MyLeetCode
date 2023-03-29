/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //一次遍历的解法
 /*
要删除倒数第n个数
那么对于每个节点，往后看n个，如果是空，它就是倒数第n个
因此，我们一次遍历当中就可以找到倒数n+1个节点，从而把下一个删除即可

对于头节点单独判断
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //尝试一趟扫描
        //往后看n+1位，是不是空指针，是就把下一个删了
        //第一个元素单独判断
        ListNode* tmp = head;
        for(int i = 1; i <= n; i++)
        {
            tmp = tmp->next;
        }
        if(tmp == nullptr)
        {
            head = head->next;
            return head;
        }
        //说明不是
        tmp = head;
        ListNode* t;
        while(tmp != nullptr)
        {
            t = tmp;
            //往后看n+1位，是不是空
            for(int i = 1; i <= n+1; i++)
            {
                t = t->next;
            }
            if(t == nullptr)
            {
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
        }
        return head;
    }
};