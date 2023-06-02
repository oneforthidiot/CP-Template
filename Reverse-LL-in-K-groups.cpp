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
    ListNode* helper(ListNode* head,int k, int sz){
        if(!head)return NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        int sz1=k;
        if(sz<k){
            return head;
        }
        while(curr and sz1--){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        if(nxt){
            sz-=k;
            head->next=helper(nxt,k,sz);
        }
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        int sz=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            sz++;
        }
        return helper(head,k,sz);

    }
};
