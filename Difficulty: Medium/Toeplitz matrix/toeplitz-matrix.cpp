//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    int len1 = mat.size(), len2;
    for(int i=0;i<len1/2;i++)
    {
        len2 = mat[i].size();
        for(int j=0;j<len2;j++)
        {
            int k = i, l = j;
            while(k<len1 and l<len2)
            {
                if(mat[k][l] != mat[i][j]) return 0;
                k++;
                l++;
            }
        }
    }
    return 1;
    // code here
}