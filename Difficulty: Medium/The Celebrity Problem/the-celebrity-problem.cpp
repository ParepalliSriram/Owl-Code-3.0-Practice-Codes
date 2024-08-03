//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int l=mat.size();
        vector<int> key(l, 0);
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(mat[i][j]==1) 
                {
                    key[i]--;
                    key[j]++;
                }
            }
        }
        for(int i=0;i<l;i++) if(key[i]==l-1) return i;
        return -1;
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
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends