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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 1;
        ListNode* mover = head;

        while(mover -> next != NULL){
            count++;
            mover = mover -> next;
        }
        if(count == 1) return nullptr;
        int pos = 0;
        if(count % 2 == 0){
            pos = (count/2) + 1;
        }else{
            pos = (count + 1)/2;
        }
        mover = head;
        for(int i = 1; i < pos - 1 ; i++){
            mover = mover -> next ;
        }
        ListNode* temp = mover -> next;
        mover -> next = mover -> next -> next;
        delete temp;
        return head;
    }
};