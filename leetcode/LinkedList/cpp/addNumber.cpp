static int x {[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}()};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int extra = 0;
        while(l1 != NULL || l2 != NULL || extra != 0) {
            int n1 = 0, n2 = 0, v = 0;
            if(l1) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                n2 = l2->val;
                l2 = l2->next;
            }
            v = n1 + n2 + extra;
            extra = v / 10;
            v = v % 10;
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        ListNode* temp = res->next;
        delete res;
        return temp;
    }
};