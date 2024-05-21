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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        map<ListNode*,int> mp;
        int pos = 1;


        ListNode* mover = head;

        while(mover -> next != nullptr){
            mp[mover]++;
            if(mp[mover] == 2){
                return true;
            }
            mover = mover -> next;
        }

        return false;
    }
};