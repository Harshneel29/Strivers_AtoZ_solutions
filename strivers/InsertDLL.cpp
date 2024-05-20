void addNode(Node *head, int pos, int data)
{
   int count = 0;
   Node* mover = head;
   Node* n = new Node(data);
   
   while(count<pos && mover -> next != NULL){
       mover = mover -> next;
       count++;
   }
   
    n -> next = mover -> next;
    if(mover -> next != NULL) mover -> next -> prev = n;
    mover -> next = n;
    n -> prev = mover;
  

}