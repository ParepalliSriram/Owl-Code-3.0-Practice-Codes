//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node * Rec(Node *t1)
    {
        if(t1->next==NULL) return t1;
        Node *t2=Rec(t1->next);
        t1->next->next=t1;
        t1->next=NULL;
        return t2;
    }
    void fun(Node *&t1, Node *&t2, int d)
    {
        Node *NN= new Node;
        NN->data=d;
        NN->next=NULL;
        if(t2==NULL)
        {
            t1=NN;
            t2=t1;
        }
        else
        {
            t2->next=NN;
            t2=t2->next;
        }
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1==NULL and node2==0) return node1;
        Node *t1=NULL, *t2=NULL;
        while(node1!=NULL and node2!=NULL)
        {
            if(node1->data < node2->data)
            {
                fun(t1, t2, node1->data);
                node1=node1->next;
            }
            else
            {
                fun(t1, t2, node2->data);
                node2=node2->next;
            }
        }
        while(node1)
        {
            fun(t1, t2, node1->data);
            node1=node1->next;
        }
        while(node2)
        {
            fun(t1, t2, node2->data);
            node2=node2->next;
        }
        t1=Rec(t1);
        return t1;
        // your code goes here
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends