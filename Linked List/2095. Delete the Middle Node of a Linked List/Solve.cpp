class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode *prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL)
             prev->next = slow->next;    // prev->next = prev->next->next;
        return head;
    }
};
