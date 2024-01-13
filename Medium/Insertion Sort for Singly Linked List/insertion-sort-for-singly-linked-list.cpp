//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    void Func(Node * &t2, Node *NN)
    {
        Node *ref=NULL;
        while(t2)
        {
            if(t2->data > NN->data)
            {
                int temp=t2->data;
                NN->next=t2->next;
                t2->data=NN->data;
                NN->data=temp;
                t2->next=NN;
                return;
            }
            if(t2->next==NULL) ref=t2;
            t2=t2->next;
            
        }
        ref->next=NN;
    }
    Node* insertionSort(struct Node* head_ref)
    {
        Node *t1=NULL, *t2;
        while(head_ref)
        {
            Node *NN=new Node(head_ref->data);
            if(t1==NULL) t1=NN;
            else 
            {
                t2=t1;
                Func(t2, NN);
            }
            head_ref=head_ref->next;
        }
        return t1;
        //code here
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends