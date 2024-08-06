//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int l=str.size(), d_c=0, key=0, s_ss=0;
        if(str[0]=='.' or str[l-1]=='.') return false;
        for(int i=0;i<l;i++)
        {
            if(str[i]=='.')
            {
                // if(key!=0) cout<<int(log10(key))+1<<" "<<s_ss<<endl;
                if((i+1<l and str[i+1]=='.') or key>255 or (key!=0 and s_ss!=int(log10(key))+1)) return false;
                d_c++;
                key=0;
                s_ss=0;
            }
            else 
            {
                s_ss++;
                key=key*10+(str[i]-'0');
            }
            
        }
        if(d_c!=3 or key>255) return false;
        return true;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends