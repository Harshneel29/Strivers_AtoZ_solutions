/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;  // handle empty list

        stack<int> st;
        ListNode* mover = head;

        // Push all node values onto the stack
        while (mover != nullptr) {
            st.push(mover->val);
            mover = mover->next;
        }

        mover = head;
        
        // Pop from stack and assign values back to the nodes
        while (!st.empty()) {
            mover->val = st.top();
            st.pop();
            mover = mover->next;
        }

        return head;
}
};