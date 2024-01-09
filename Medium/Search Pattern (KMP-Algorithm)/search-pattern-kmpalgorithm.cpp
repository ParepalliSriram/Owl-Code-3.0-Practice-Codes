//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> vec;
            if(txt.size() < pat.size()) 
            {
                vec.push_back(-1);
                return vec;
            }
            int i=0;
            bool t;
            int k, m, count=0, l, r;
            while(i<txt.size())
            {
                k=0;
                m=i;
                t=true;
                l=i;
                count=0;
                r=0;
                while(k<pat.size() and m<txt.size())
                {
                    if(pat[k]!=txt[m])
                    {
                        t=false;
                        break;
                    }
                    else r++;
                    if(pat[k]==txt[l]) count++;
                    k++;
                    m++;
                }
                if(t and r==pat.size()) vec.push_back(i+1);
                if(count>1) i++;
                else if(count==1) i=m;
                else i++;
            }
            if(vec.size()==0) vec.push_back(-1);
            return vec;
            //code here
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends