class Solution {
public:
    ListNode* findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeTwoLists(ListNode *listOne, ListNode* listTwo) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(listOne != NULL && listTwo != NULL) {
            if(listOne->val < listTwo->val) {
                temp->next = listOne;
                temp = listOne;
                listOne = listOne->next;
            }
            else {
                temp->next = listTwo;
                temp = listTwo;
                listTwo = listTwo->next;
            }
        }
        if(listOne) 
            temp->next = listOne;
        else
            temp->next = listTwo;

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *left = head;
        ListNode *mid = findMiddle(head);
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left, right);
    }
};
