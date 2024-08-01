//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int i=0, j=0, iter=1, row=matrix.size(), col=matrix[0].size();
        vector<int> key;
        while(1)
        {
            if(i<row and j<col and i>=0 and j>=0 and matrix[i][j]!=-1)
            {
                key.push_back(matrix[i][j]);
                matrix[i][j]=-1;
            }
            else break;
            if(iter == 1)
            {
                if(j+1>=col or matrix[i][j+1]==-1)iter=2;
                else j++;
            }
            if(iter==2)
            {
                if(i+1>=row or matrix[i+1][j]==-1) iter=3;
                else i++;
            }
            if(iter==3)
            {
                if(j-1<0 or matrix[i][j-1]==-1) iter=4;
                else j--;
            }
            if(iter==4)
            {
                if(i-1<0 or matrix[i-1][j]==-1)
                {
                    iter=1;
                    j++;
                }
                else i--;
            }
        }
        return key;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends