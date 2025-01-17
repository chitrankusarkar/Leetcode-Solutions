class Solution {
public:
    ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (listA != NULL && listB != NULL) {
            if (listA->val < listB->val) {
                temp->next = listA;
                temp = listA;
                listA = listA->next;
            } else {
                temp->next = listB;
                temp = listB;
                listB = listB->next;
            }
        }
        if (listA)
            temp->next = listA;
        else
            temp->next = listB;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(lists[i], head);
        }
        return head;
    }
};
