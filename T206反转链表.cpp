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

//看了题解的双指针方法觉得很好，但是自己写的递归也还行
//感觉两种方法共同之处就是会提前记录下一个方块的位置

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *ans;
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else
        {
            //递归啦
            ans = reverseList(head->next);  //翻转剩余的部分，不需要记录返回值
            head->next->next = head;  //再把p挂在最后
            //一定一定要注意，
            head->next = nullptr;
            return ans;
        }
    }
};