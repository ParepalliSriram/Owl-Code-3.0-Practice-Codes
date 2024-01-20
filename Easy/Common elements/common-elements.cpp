//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> vec;
            n1--;
            n2--;
            n3--;
            while(n1>=0 and n2>=0 and n3>=0)
            {
                if(A[n1]==B[n2] and A[n1]==C[n3])
                {
                    if(find(vec.begin(), vec.end(), A[n1])==vec.end()) vec.insert(vec.begin(), A[n1]);
                    n1--;
                    n2--;
                    n3--;
                }
                else 
                {
                    if(A[n1]<B[n2]) n2--;
                    else if(A[n1]!=B[n2]) n1--;
                    if(B[n2]<C[n3]) n3--;
                    else if(B[n2]!=C[n3]) n2--;
                }
            }
            return vec;
            //code here.
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends