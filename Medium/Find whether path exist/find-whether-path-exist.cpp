//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int Helper(vector<vector<int>> &grid, int n, int i, int j, vector<vector<int>> &vis)
    {
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==0) return 0;
        if(grid[i][j]==2) return 1;
        if(vis[i][j]==1) return 0;
        vis[i][j]=1;
        return max({Helper(grid, n, i-1, j, vis), Helper(grid, n, i, j+1, vis), Helper(grid, n, i+1, j, vis), Helper(grid,n, i, j-1, vis)});
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
                    if(Helper(grid, n, i, j, vis)) return true;
                    break;
                }
            }
        }
        return false;
        //code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends