//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    map<vector<int>, int> mp;
    void Helper(vector<int> &arr, int n, int i, vector<int> &v, vector<int> vis, vector<vector<int>> &vec)
    {
        if(i>=n)
        {
            if(mp[v]==0) vec.push_back(v);
            mp[v]++;
            // if(find(vec.begin(), vec.end(), v)==vec.end()) vec.push_back(v);
            return;
        }
        for(int k=0;k<n;k++)
        {
            if(vis[k]==0)
            {
                vis[k]=1;
                v.push_back(arr[k]);
                Helper(arr, n, i+1, v, vis, vec);
                vis[k]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> vec;
        vector<int> v, vis(n, 0);
        Helper(arr, n, 0, v, vis, vec);
        sort(vec.begin(), vec.end());
        return vec;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends