//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* addSame(struct Node* first,struct Node* second,int* rem){
        if(!first and !second)return NULL;
        struct Node* res=new Node(NULL);
        res->next=addSame(first->next,second->next,rem);
        int sum=first->data+second->data+ *rem;
        *rem=sum/10;
        res->data=sum%10;
        return res;
    }
    void addCarry(struct Node* head,struct Node* curr,int *carry,struct Node* &res){
        if(head!=curr){
            addCarry(head->next,curr,carry,res);
            int sum=head->data+ *carry;
            *carry=sum/10;
            sum%=10;
            struct Node* new_node=new Node(sum);
            new_node->next=res;
            res=new_node;
        }
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        int sz1=0;
        int sz2=0;
        Node* p1=first;
        Node* p2=second;
        while(p1){
            p1=p1->next;
            sz1++;
        }
        while(p2){
            p2=p2->next;
            sz2++;
        }
        int carry=0;
        struct Node* res=new Node(0);
        if(sz1==sz2){
            res=addSame(first,second,&carry);
        }
        else
        if(sz1>sz2){
            int diff=abs(sz1-sz2);
            struct Node* curr=first;
            while(diff--)curr=curr->next;
            res=addSame(curr,second,&carry);
            addCarry(first,curr,&carry,res);
        }
        else{
            int diff=abs(sz1-sz2);
            struct Node* curr=second;
            while(diff--)curr=curr->next;
            res=addSame(curr,first,&carry);
            addCarry(second,curr,&carry,res);
        }
        if(carry){
            int sum=carry;
            carry=sum/10;
            sum%=10;
            struct Node* new_node=new Node(sum);
            new_node->next=res;
            res=new_node;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
