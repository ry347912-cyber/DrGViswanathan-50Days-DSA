class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || !k) return head;

        int n = 1;
        ListNode *t = head;

        while(t->next) t = t->next, n++;

        k %= n;
        if(!k) return head;

        t->next = head;

        for(int i=0;i<n-k;i++)
            t = t->next;

        head = t->next;
        t->next = NULL;

        return head;
    }
};