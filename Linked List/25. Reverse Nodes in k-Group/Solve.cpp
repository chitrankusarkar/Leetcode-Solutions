class Solution {
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; 
    }
    
    ListNode* kThNode(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 1;
        while(temp != NULL) {
            if(cnt == k)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return NULL;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* previousEndedGrp = dummy;

        while(1) {
            ListNode* kthNode = kThNode(previousEndedGrp->next, k);
            if(kthNode == NULL)
                break;
        
            ListNode* nextStartGrp = kthNode->next;
            ListNode* temp = previousEndedGrp->next;
            kthNode->next = NULL;

            ListNode* newHead = reverseLL(temp);
            previousEndedGrp->next = newHead;
            temp->next = nextStartGrp;
            previousEndedGrp = temp;
        }
        return dummy->next;
    }
};
