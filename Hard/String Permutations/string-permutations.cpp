//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void Helper(string s, vector<string> &vec, vector<int> &vis, string str)
    {
        if(str.size()==s.size())
        {
            vec.push_back(str);
            return;
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                Helper(s, vec, vis, str+s[i]);
                vis[i]=0;
            }
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> vec;
        vector<int> vis(S.size(), 0);
        Helper(S, vec, vis, "");
        sort(vec.begin(), vec.end());
        return vec;
        //Your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends