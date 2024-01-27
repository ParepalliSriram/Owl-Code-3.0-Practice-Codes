//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void Helper(string s, vector<int> &vis, vector<string> &vec, string str)
	    {
	        if(str.size()==s.size())
	        {
	            if(find(vec.begin(), vec.end(), str)==vec.end()) vec.push_back(str);
	            return;
	        }
	        for(int i=0;i<vis.size();i++)
	        {
	            if(vis[i]==0)
	            {
	                vis[i]=1;
	                Helper(s, vis, vec, str+s[i]);
	                vis[i]=0;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<int> vis(S.size(), 0);
		    vector<string> vec;
		    Helper(S, vis, vec, "");
		    sort(vec.begin(), vec.end());
		    return vec;
		    // Code here there
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends