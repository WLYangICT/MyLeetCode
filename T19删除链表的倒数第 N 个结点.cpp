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
 //简单题，题目说的那个挑战一次遍历倒是可以再想想
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        //先进行一次遍历获取链表长度
        ListNode* tmp = head;
        while(tmp != nullptr)
        {
            len++;
            tmp = tmp->next;
        }
        int index = len - n + 1;
        if(index == 1)
        {
            //删除头节点
            head = head->next;
        }
        else
        {
            int ptr = 1;
            tmp = head;
            while(ptr < index - 1)
            {
                tmp = tmp->next;
                ptr++;
            }
            //ptr == index - 1，删除下一节点
            tmp->next = tmp->next->next;
        }
        return head;
    }
};


//一次遍历版本题解
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