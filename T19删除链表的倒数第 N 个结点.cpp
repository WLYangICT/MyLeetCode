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