class Solution {
    ListNode* findNthNode(ListNode* head, int n) {
        int cnt = 1;
        while(head != NULL) {
            if(cnt == n)
                return head;
            cnt++;
            head = head->next;
        }
        return head;
    } 
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int cnt = 1;
        ListNode* temp = head;
        while(temp->next != NULL) {
            cnt++;
            temp = temp->next;
        }
        if(k % cnt == 0)
            return head;
        k %= cnt;
        temp->next = head;
        ListNode* nThNode = findNthNode(head, cnt - k);
        head = nThNode->next;
        nThNode->next = NULL;
        return head;
    }
};
