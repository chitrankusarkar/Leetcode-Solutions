class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(auto it: nums)
            s.insert(it);
        ListNode* temp = head;
        while(temp != NULL) {
            if(s.count(temp->val))
                temp = temp->next;
            else
                break;
        }
        ListNode* newHead = temp;
        while(temp != NULL && temp->next != NULL) {
            if(s.count(temp->next->val))
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return newHead;
    }
};
