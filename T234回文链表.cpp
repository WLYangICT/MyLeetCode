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
class Solution {
public:
    /* 比较暴力的方法，一次迭代拷贝到数组里面，然后看数组是不是就行了，数组判断很容易
    不过这种方法时间复杂度O(n)，空间复杂度O(n)，能AC，就是不能达到进阶要求
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode* p = head;
        while(p != nullptr)
        {
            list.push_back(p->val);
            p = p->next;
        }
        //直接看数组是不是就行了
        for(int i = 0; i < (list.size()/2); i++)
        {
            if(list[i] != list[list.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    */

    //上一题写的反转链表函数，直接用了
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

    bool isPalindrome(ListNode* head) {
        //一次遍历记录链表长度
        ListNode* p = head;
        int len = 0;
        while(p != nullptr)
        {
            len++;
            p = p->next;
        }
        if(len == 1)
        {
            return true;
        }
        //再次遍历记录第二般部分的头节点
        ListNode* head2;
        p = head;
        int count = 0;
        while(p != nullptr)
        {
            count++;
            if(count >= (len /2))
            {
                //找完一半了
                if(len % 2 == 0)
                {
                    //偶数个，下半段就是下一个开始
                    head2 = p->next;
                }
                else
                {
                    //奇数个，就是下下个
                    head2 = p->next->next;
                }
                break;
            }
            p = p->next;
        }
        head2 = reverseList(head2);
        //然后逐个比较就行
        while(head2 != nullptr)
        {
            if(head2->val != head->val)
            {
                return false;
            }
            head2 = head2->next;
            head = head->next;
        }
        return true;
    }
};