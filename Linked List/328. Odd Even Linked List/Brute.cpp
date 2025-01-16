class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
      // If last node is not covered within loop
        if(temp)
            arr.push_back(temp->val);
        temp = head->next;
        while(temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
      // If last node is not covered within loop
        if(temp)
            arr.push_back(temp->val);
        temp = head;
        int i = 0;
        while(temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        temp = head;
        return temp;
    }
};
