//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bitset<30> ru, rl, rr;
    void Helper(int n, int i, vector<vector<int>> &vec, vector<int> &v)
    {
        if(i>=n)
        {
            vec.push_back(v);
            return;
        }
        for(int k=0;k<n;k++)
        {
            if(!ru[k] and !rl[i-k+n-1] and !rr[i+k])
            {
                ru[k]=rl[i-k+n-1]=rr[i+k]=1;
                v.push_back(k+1);
                Helper(n, i+1, vec, v);
                v.pop_back();
                ru[k]=rl[i-k+n-1]=rr[i+k]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> vec;
        vector<int> v;
        Helper(n, 0, vec, v);
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
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends