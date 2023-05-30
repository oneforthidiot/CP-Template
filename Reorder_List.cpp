class Solution {
public:
    ListNode* rev(ListNode* mid){
        ListNode* curr=mid;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next)return;
        ListNode* p1=head;
        ListNode* p2=head;
        while(p2 and p2->next){
            p1=p1->next;
            p2=p2->next->next;
        }
        ListNode* r=rev(p1);
        ListNode* l=head->next;
        for(int i=0;l!=r;i++,head=head->next){
            if(i&1){
                head->next=l;
                l=l->next;
            }
            else{
                head->next=r;
                r=r->next;
            }
        }
        // while(r){
        //     cout<<r->val<<" ";
        //     r=r->next;
        // }

    }
