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
//两点相加，最多进一
class Solution {
public:
    int getLength(ListNode* l){
        ListNode* tmp = l;
        int count = 0;
        while(tmp != nullptr){
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    ListNode* getLast(ListNode* l){
        ListNode* tmp = l;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        return tmp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        ListNode* last1 = getLast(l1);
        ListNode* last2 = getLast(l2);
        if(len1 > len2){
            //链表2补齐
            int delt = len1 - len2;
            ListNode* tmp = last2;
            for(int i =1;i<=delt;i++){
                ListNode* ln = new ListNode(0);
                tmp->next = ln;
                tmp = tmp->next;
            }
        }
        else if(len1 < len2){
            int delt = len2 - len1;
            ListNode* tmp = last1;
            for(int i =1;i<=delt;i++){
                ListNode* ln = new ListNode(0);
                tmp->next = ln;
                tmp = tmp->next;
            }
        }
        else{

        }
        //补齐之后开始计算
        int carry = 0;
        ListNode *p1, *p2;
        p1 = l1;
        p2 = l2;
        while(p1 != nullptr){
            int a = p1->val;
            int b = p2->val;
            int sum = a + b + carry;
            if(sum >= 10){
                carry = 1;
                sum = sum - 10;
            }else{
                carry = 0;
            }
            p1->val = sum;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(carry > 0){
            ListNode* nl = new ListNode(carry);
            ListNode* tail = getLast(l1);
            tail->next = nl;
        }else{

        }
        return l1;
    }
};