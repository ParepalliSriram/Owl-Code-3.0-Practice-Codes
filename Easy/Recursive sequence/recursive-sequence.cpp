//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int mod=1000000007;
    long long sequence(int n){
        long long c, an=0, count=1;
        for(int i=1;i<=n;i++)
        {
            c=1;
            for(int j=1;j<=i;j++)
            {
                c=(c*count)%mod;
                count++;
            }
            an=(an+c)%mod;
        }
        return an%mod;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends