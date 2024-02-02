//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int j=0, p=1;
        if(s[0]=='-')
        {
            p=-1;
            j++;
        }
        int c=0;
        while(j<s.size())
        {
            if(s[j]>='0' and s[j]<='9') c=c*10+(s[j]-'0');
            else return -1;
            j++;
        }
        c*=p;
        return c;
        
        //Your code here
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends