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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        ListNode* temp=NULL;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(!left)return right;
        if(!right)return left;
        ListNode* nw=new ListNode(-1);
        ListNode* temp=nw;
        while(left and right){
            if(left->val>right->val){
                temp->next=right;
                temp=right;
                right=right->next;
            }
            else{
                temp->next=left;
                temp=left;
                left=left->next;
            }
        }
        while(left){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        return nw->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)return head;
        ListNode* mid=findmid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
        ListNode* ret=merge(left,right);
        return ret;
    }
};
