class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head -> next == NULL && n == 1) return NULL;
        
        ListNode* curr = head;
        int cnt=1;
        while(curr->next != NULL){
            curr = curr->next;
            cnt++;
        }
        curr = head; 
        int pos = cnt - n;
        for(int i=1;i<pos;i++){
            curr = curr->next;
        }
        if(pos == 0) head = head->next;
        else curr->next = curr->next->next;
        return head;
}
};