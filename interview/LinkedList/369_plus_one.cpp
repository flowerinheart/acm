//1. 递归求解或者栈
//2. 下面这种方法比较巧妙了，思路是遍历链表，找到右起第一个不为9的数字，如果找不到这样的数字，说明所有数字均为9，那么在表头新建一个值为0的新节点，进行加1处理，然后把右边所有的数字都置为0即可。

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *cur = head, *right = NULL;
        while (cur->next != NULL && cur->val == 9) {
            cur = cur->next;
            cur->val = 0;
        }
        if(cur->val == 9)
            cur->next = new ListNode(1);
        else
            cur->val += 1;
        return head;
        
    }
};