class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> list;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                list.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(list.begin(), list.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for (int val : list) { 
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummy->next;
    }
};
