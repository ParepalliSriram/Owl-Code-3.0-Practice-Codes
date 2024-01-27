//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *Helper(struct node *head, int k, struct node *&rem)
    {
        if(k<=1 or head==NULL or head->next==NULL)
        {
            if(head) rem=head->next;
            return head;
        }
        struct node *temp=Helper(head->next, k-1, rem);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    struct node *reverseIt (struct node *head, int k)
    { 
        struct node *t1=NULL, *t2;
        while(head)
        {
            struct node *rem=NULL;
            if(t1==NULL)
            {
                t1=Helper(head, k, rem);
                head->next=rem;
            }
            else
            {
                t2=head->next;
                if(t2==NULL) break;
                head->next=Helper(head->next, k, rem);
                head=t2;
                head->next=rem;
            }
        }
        return t1;
        // Complete this method
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends