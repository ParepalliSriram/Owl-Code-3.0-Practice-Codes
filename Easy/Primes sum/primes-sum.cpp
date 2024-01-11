//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    static const int n=100001;
    int prime[n];
    Solution()
    {
        Prime();
    }
    void Prime()
    {
        memset(prime, 1, sizeof(prime));
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;i++) if(prime[i]) for(int k=i*i;k<=n;k+=i) prime[k]=0;
    }
    string isSumOfTwo(int N){
        int i=2, k=N;
        int count=0;
        while(i<=k)
        {
            if(prime[i] and prime[k]) 
            {
                if(i+k == N) return "Yes";
                else if(i+k > N) k--;
                else i++;
            }
            else if(prime[i] and prime[k]!=1) k--;
            else i++;
            // cout<<i<<" "<<k<<"\n";
            // if(count==15)
            // break;
            count++;
        }
        return "No";
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends