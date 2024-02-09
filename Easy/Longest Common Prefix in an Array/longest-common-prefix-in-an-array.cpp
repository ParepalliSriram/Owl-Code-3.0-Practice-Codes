//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        if(N==1) return arr[0];
        string str="";
        bool ack;
        char c;
        for(int i=0;i<arr[0].size();i++)
        {
            c=arr[0][i];
            ack=false;
            for(int j=0;j<N;j++)
            {
                if(i>=arr[j].size() or arr[j][i]!=c)
                {
                    ack=true;
                    break;
                }
            }
            if(ack) break;
            str+=c;
        }
        if(str.size()==0) str="-1";
        return str;
        // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends