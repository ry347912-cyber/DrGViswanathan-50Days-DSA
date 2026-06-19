class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                int val = curr->val;
                while (curr != NULL && curr->val == val) {
                    curr = curr->next;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
