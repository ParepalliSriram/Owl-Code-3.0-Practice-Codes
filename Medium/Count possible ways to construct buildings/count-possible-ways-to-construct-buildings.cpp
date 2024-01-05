//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    if(N==1) return 4;
	    if(N==2) return 9;
	    long long int a=2, b=3, temp;
	    N-=2;
	    while(N>0)
	    {
	        temp=a+b;
	        temp%=(1000000007);
	        a=b;
	        b=temp;
	        N--;   
	    }
	    return (b*b)%(1000000007);
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends