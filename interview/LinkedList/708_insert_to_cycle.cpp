

// 在循环有序的链表中插入结点，要求插入结点后，链表仍保持有序且循环, 并返回
// 当链表为空时，我们插入结点即要生成一个新的循环有序链表
// 最常见的情况就是要插入的结点值在两个有序结点值[a, b]之间，那么只要满足 a <= insertVal <= b 即可
// 其次是遇到链表表尾的节点要特殊判断下

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *temp = new Node(insertVal, nullptr);
        if(head == nullptr) {
            temp->next = temp;
            return temp;
        }
        Node* pre = head, *cur = pre->next;
        while(cur != head) {
            if(insertVal >= pre->val && insertVal <= cur->val)
                break;
            if(pre->val > cur->val && (insertVal >= pre->val || insertVal <= cur->val))
                break;
        }
        pre->next = temp;
        temp->next = cur;
        return head;
    }
};