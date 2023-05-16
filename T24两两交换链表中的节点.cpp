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

/*
没有什么算法可言，一次遍历，用五个指针记录当前两个点，往后两个点，上面一个点
顺着走一遍就交换完了，细节比较重要
模拟以下
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *p1 = head, *p2 = head->next, *p1n, *p2n, *last = nullptr;
        while(p1 != nullptr && p2 != nullptr)
        {
            //先把后面要去的地址存好
            p1n = p2->next;
            if(p1n == nullptr)
            {
                p2n = nullptr;
            }
            else
            {
                p2n = p1n->next;
            }
            //交换顺序
            p2->next = p1;
            p1->next = p1n;
            //和上一段的衔接也要换呀
            if(last == nullptr)
            {
                //不用和上一段衔接，但是要换head
                head = p2;
            }
            else
            {
                last->next = p2;
            }
            last = p1;
            p1 = p1n;
            p2 = p2n;
        }
        return head;
    }
};