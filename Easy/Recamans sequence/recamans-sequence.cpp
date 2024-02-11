//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        unordered_map<int, int> mp;
        vector<int> vec;
        vec.push_back(0);
        mp[0]++;
        int a;
        for(int i=1;i<n;i++)
        {
            a=vec[i-1]-i;
            if(a<0 or mp[a]!=0) 
            {
                vec.push_back(vec[i-1]+i);
                mp[vec[i-1]+i]++;
            }
            else
            {
                vec.push_back(a);
                mp[a]++;
            }
        }
        return vec;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends