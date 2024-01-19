//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int Helper(int a, int b, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=a or j>=b) return 0;
        if(i==a-1 and j==b-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=Helper(a, b, i+1, j, dp)+Helper(a, b, i, j+1, dp);
    }
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
        int an=Helper(a, b, 0, 0, dp);
        return an;
        //code here
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends