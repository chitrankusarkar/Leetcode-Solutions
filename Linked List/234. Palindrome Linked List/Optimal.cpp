class Solution {
    ListNode* middleOfLL(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
    ListNode* reverseHalfLL(ListNode* head) {
        ListNode* newHead = middleOfLL(head);
        ListNode* front = NULL;
        ListNode* prev = NULL;
        ListNode* temp = newHead;
        while(temp != NULL) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* halfReversed = reverseHalfLL(head);
        ListNode* temp = head;
        while(halfReversed != NULL) {
            if(temp->val != halfReversed->val)
                return false;
            temp = temp->next;
            halfReversed = halfReversed->next;
        }
        return true;
    }
};
