//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// By Binary Exponentiation 

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int an=1;
		    while(n)
		    {
		        if(n&1)
		        {
		            n-=1;
		            an=(an*x)%M;
		        }
		        else
		        {
		            n/=2;
		            x=(x*x)%M;
		        }
		    }
		    return an;
		    // Code here
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
