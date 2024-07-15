//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        string str="";
        int i=0;
        while(i<d)
        {
            if(s==0)
            {
                str[i-1]=((str[i-1]-'0')-1)+'0';
                str+='1';
            }
            else 
            {
                if(s>9) 
                {
                    str+='9';
                    s-=9;
                }
                else
                {
                    str+=(s+'0');
                    s=0;
                }
            }
            i++;
        }
        if(s!=0) str="-1";
        else
        {
            int si=str.size();
            for(int i=0;i<si/2;i++) 
            {
                int t=str[i];
                str[i]=str[si-i-1];
                str[si-i-1]=t;
            }
        }
        return str;
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends