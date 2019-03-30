// class Solution {
// public:
//     Node* treeToDoublyList(Node* root) {
//         if (!root) return NULL;
//         Node *head = NULL, *pre = NULL;
//         inorder(root, pre, head);
//         pre->right = head;
//         head->left = pre;
//         return head;
//     }
//     //*&使得可以修改指针
//     void inorder(Node* node, Node*& pre, Node*& head) {
//         if (!node) return;
//         inorder(node->left, pre, head);
//         if (!head) {
//             head = node;
//             pre = node;
//         } else {
//             pre->right = node;
//             node->left = pre;
//             pre = node;
//         }
//         inorder(node->right, pre, head);
//     }
// };
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