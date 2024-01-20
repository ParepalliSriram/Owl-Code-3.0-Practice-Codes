//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> vec;
        int i=0, j=0;
        while(j<m)
        {
            if(matrix[i][j]!=-1) vec.push_back(matrix[i][j]);
            matrix[i][j]=-1;
            j++;
        }
        i++;
        j=m-1;
        while(i<n)
        {
            if(matrix[i][j]!=-1) vec.push_back(matrix[i][j]);
            matrix[i][j]=-1;
            i++;
        }
        j--;
        i=n-1;
        while(j>=0)
        {
            if(matrix[i][j]!=-1) vec.push_back(matrix[i][j]);
            matrix[i][j]=-1;
            j--;
        }
        i--;
        j=0;
        while(i>0)
        {
            if(matrix[i][j]!=-1) vec.push_back(matrix[i][j]);
            matrix[i][j]=-1;
            i--;
        }
        return vec;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends