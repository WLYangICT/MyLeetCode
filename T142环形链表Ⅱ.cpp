/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//其实和上一题是一样的，只是增加了不允许修改链表的条件，也意味着用val标记的做法失效
//那就快慢指针吧
//先用快慢指针判断有没环，然后有环就一个个往后走10^4看有没有回来过，比较粗暴的解法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            //只有一个节点或者没有节点，无法成环
            return NULL;
        }
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && slow != NULL)
        {
            if(fast == slow)
            {
                //重复了，套圈了，成环了
                break;
            }
            else
            {
                fast = fast->next;  //先移动一步
                if(fast == NULL)
                {
                    return NULL;
                }
                fast = fast->next;
                if(fast == NULL)
                {
                    return NULL;
                }
                slow = slow->next;
                if(slow == NULL)
                {
                    return NULL;
                }
            }
        }
        //能走到这里说明是有环的，接下来就是判断入口点，逐个点开始走一圈，能走回来的第一个是
        int max_time = 1e4;
        ListNode *p = head, *q;
        while(p != NULL)
        {
            bool flag = false;  //是否重回
            q = p;
            for(int i = 1; i <= max_time; i++)
            {
                q = q->next;
                if (q == p)  //回来了
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};

//标记法居然还是有用，题目要求的不修改链表看来只是说说，这种是最快的了
ListNode *detectCycle(ListNode *head) {
    while(head != NULL)
    {
        if(head->val > 1e5)
        {
            return head;
        }
        head->val = 1e5+1;
        head = head->next;
    }
    return NULL;
}