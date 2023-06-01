void rearrangeEvenOdd(Node *head)
    {
       if(!head or !head->next)return;
       Node* temp=head;
       Node* evenStart=NULL;
       Node* oddStart=NULL;
       Node* evenEnd=NULL;
       Node* oddEnd=NULL;
       int i=1;
       while(temp){
           if(i%2){
               if(!oddStart){
                   oddStart=temp;
               }
               else{
                   oddEnd->next=temp;
               }
               oddEnd=temp;
           }
           else{
               if(!evenStart){
                   evenStart=temp;
               }
               else{
                   evenEnd->next=temp;
               }
               evenEnd=temp;
           }
           i++;
           temp=temp->next;
       }
       oddEnd->next=evenStart;
       evenEnd->next=NULL;
       head=oddStart;
    }
