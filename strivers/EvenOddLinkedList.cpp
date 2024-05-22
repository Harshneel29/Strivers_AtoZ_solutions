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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head ->next == NULL) return head;
        ListNode* mover1 = head;
        ListNode* mover2 = mover1 -> next;
        ListNode* head2 = mover2;

        while(mover1 -> next != NULL && mover2 -> next != NULL){
            mover1 -> next = mover1 -> next ->next;
            mover1 = mover1 -> next;
            mover2 -> next = mover2 -> next ->next;
            mover2 = mover2 -> next;
        }

        mover1 -> next = head2;
        return head;
    }
};