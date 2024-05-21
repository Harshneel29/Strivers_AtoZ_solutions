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
    ListNode* middleNode(ListNode* head) {
        int count = 1;
        int pos = 0;
        ListNode* mover = head;

        while(mover -> next != NULL){
            count++;
            mover = mover -> next;
        }

        if(count % 2 != 0){
            pos = (count + 1)/2;
        }else{
            pos = (count/2) + 1;
        }
        ListNode* temp = head;
        while(pos>1){
            temp = temp -> next;
            pos--;
        }


        return temp;
    }
};