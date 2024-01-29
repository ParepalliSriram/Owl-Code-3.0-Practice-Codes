//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void Helper(int n, int op, int cl, vector<string> &vec, string str)
    {
        if(op==n and cl==n)
        {
            vec.push_back(str);
            return;
        }
        if(op < n) Helper(n, op+1, cl, vec, str+'(');
        if(op > cl) Helper(n, op, cl+1, vec, str+')');
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> vec;
        Helper(n, 0, 0, vec, "");
        return vec;
        // Your code goes here 
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
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends