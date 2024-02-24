//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int st[1000001];
        int Helper(int a)
        {
            if(((a/2)+(a/3)+(a/4)) <= a) return a;
            if(st[a]!=-1) return st[a];
            return st[a]=Helper(a/2)+Helper(a/3)+Helper(a/4);
        }
        int maxSum(int n)
        {
            memset(st, -1, sizeof(st));
            int m=Helper(n);
            return m;
            //code here.
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends