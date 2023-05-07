
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode next;
      ListNode(int x)  val(x), next(NULL) {}
  };
 
class Solution {
public
     方法一：暴力打，时间复杂度O(mn)，空间复杂度O(1)
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pa = headA;
        ListNode ans = NULL;
        ListNode pb;
        int find_flag = false;
        while(pa != NULL)
        {
            pb = headB;
            find_flag = false;
            while(pb != NULL)
            {
                if(pb == pa)
                {
                    find_flag = true;
                    ans = pa;
                    break;
                }
                pb = pb-next;
            }
            if(find_flag)
            {
                break;
            }
            pa = pa-next;
        }
        return ans;
    }
    
    这种双链表方法简直神了，核心点就是AB各自走一遍，有相交一定会在某一步重合
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode A = headA, B = headB;
        while(A != B)
        {
            A = (A != NULL)  A-next  headB;
            B = (B != NULL)  B-next  headA;
        }
        return A;
    }
};