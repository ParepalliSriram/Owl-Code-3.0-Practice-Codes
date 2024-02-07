//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int ind1=0, ind2=0, req=0;
    void Helper2(Node *root, int b, bool &ack, int i, unordered_map<int, int> mp)
    {
        if(root==NULL) return;
        if(root->data==b) 
        {
            ind2=i;
            ack=true;
        }
        if(!ack) Helper2(root->left, b, ack, i+1, mp); 
        if(!ack) Helper2(root->right, b, ack, i+1, mp);
        if(ack==true and !req and mp[root->data]!=0) req=mp[root->data];
        
    }
    void Helper1(Node *root, int a, bool &ack, int i, unordered_map<int, int> &mp)
    {
        
        if(root==NULL) return;
        
        if(root->data==a) 
        {
            ind1=i;
            ack=true;
        }
        
        if(!ack) Helper1(root->left, a, ack, i+1, mp); 
        if(!ack) Helper1(root->right, a, ack, i+1, mp);
        if(ack==true) mp.insert({root->data, i});
    }
    int findDist(Node* root, int a, int b) {
        unordered_map<int, int> mp;
        bool ack=false;
        Helper1(root, a, ack, 0, mp);
        ack=false;
        Helper2(root, b, ack, 0, mp);
        return abs((req-ind1)+(req-ind2));
        // Your code here
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends