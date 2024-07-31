//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string s=arr[0], key="";
        int tor=0;
        for(int i=0;i<s.size();i++)
        {
            for(auto it: arr) if(i>=it.size() or it[i]!=s[i])
            {
                tor=1;
                break;
            }
            if(tor) break;
            key+=s[i];
        }
        if(key=="") return "-1";
        return key;
        // your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends