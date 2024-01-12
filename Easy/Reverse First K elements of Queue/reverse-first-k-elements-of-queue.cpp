//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    void Fun(queue<int> &q, int k, queue<int> &q1, stack<int> &st)
    {
        if(q.empty())
        {
            return;
        }
        if(k>0) st.push(q.front());
        else q1.push(q.front());
        q.pop();
        Fun(q, k-1, q1, st);
        if(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        else
        {
            q.push(q1.front());
            q1.pop();
        }
    }
    queue<int> modifyQueue(queue<int> q, int k) {
        queue<int> q1;
        stack<int> st;
        Fun(q, k, q1, st);
        return q;
        // add code here.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends