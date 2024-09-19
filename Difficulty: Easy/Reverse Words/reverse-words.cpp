//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string key = "", s = "";
        bool t = false;
        for(char it: str)
        {
            if(it == '.')
            {
                if(t) s+=it;
                t = true;
                s += key;
                key = s;
                s = "";
            }
            else s += it;
        }
        s += '.';
        s += key;
        return s;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends