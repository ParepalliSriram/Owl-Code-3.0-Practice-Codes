//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    string Helper(string act, int pos, string it, int itlen)
    {
        string s="";
        for(int i=0;i<itlen;i++)
        {
            if(act[pos] != it[i]) break;
            s+=it[i];
            pos++;
        }
        return s;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        map<char, vector<string>> mp;
        for(auto it: dictionary) mp[it[0]].push_back(it);
        string s1="", s2="";
        queue<string> q;
        q.push(s1);
        int i=1, l=s.size(), p;
        while(!q.empty() and i<l)
        {
            s1=q.front();
            // cout<<s1<<"\n";
            i=s1.size();
            q.pop();
            if(i>=l) continue;
            // else if(mp.find(s[i])==mp.end()) return 0;
            for(auto it: mp[s[i]])
            {
                p=it.size();
                if(p <= l-i)             ////////////////
                {
                    s2=Helper(s, i, it, p);
                    // cout<<s1+s2<<" <s2\n";
                    if(s1+s2 == s) return 1;
                    q.push(s1+s2);
                }
            }
        }
        return 0;
        //code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends