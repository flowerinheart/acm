/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL)
            return NULL;
        ListNode *t1 = pListHead, *t2 = pListHead;
        for(int i = 0; i < k - 1; i++) {
            if(t2->next == NULL)
                return NULL;
            t2 = t2->next;
        }
        while(t2->next != NULL) {
            t2 = t2->next;
            t1 = t1->next;
        }
        return t1;
    }
};