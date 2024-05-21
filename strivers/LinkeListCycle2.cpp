/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        map<ListNode*,int> mp;
        ListNode* mover = head;

        while(mover -> next != NULL){
            mp[mover]++;
            if(mp[mover] == 2){
                return mover;
            }
            mover = mover -> next;
        }

        return nullptr;
    }
};