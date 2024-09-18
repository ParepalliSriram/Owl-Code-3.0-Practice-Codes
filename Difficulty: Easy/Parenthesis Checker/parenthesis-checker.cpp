//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> sj;
        for(char it: x)
        {
            if((!sj.empty()) and ((sj.top()=='(' and it==')') or (sj.top()=='[' and it==']') or (sj.top()=='{' and it=='}')))
            {
                sj.pop();
            }
            else sj.push(it);
        }
        if(sj.empty()) return true;
        return false;
        // Your code here
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends