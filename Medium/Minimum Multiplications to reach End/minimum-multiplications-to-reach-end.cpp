//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        queue<pair<int, int>>q;
        q.push(make_pair(start, 0));
        vector<int> vis(100001, 0);
        int a, b, ack=1, mod=100000, ind;
        while(!q.empty() and ack)
        {
            a=q.front().first;
            ind=q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++)
            {
                b=(a*arr[i])%mod;
                if(vis[b]==0)
                {  
                    if(b == end) 
                    {
                        ack=0;
                        break;
                    }
                    vis[b]=1;
                    q.push(make_pair(b, ind+1));
                }
            }
        }
        if(ack==1) return -1;
        return ind+1;
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends