//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void Alexander_Helper(vector<vector<char>> grid, int i, int j, int row, int col, string word, int iter, int len, int &key, int pin)
    {
        if(i<0 or j<0 or i>=row or j>=col or iter>=len or grid[i][j]!=word[iter] or key==1) return;
        if(iter == len-1 and grid[i][j]==word[iter])
        {
            key=1;
            return;
        }
        // cout<<grid[i][j]<<endl;
        switch(pin)
        {
            
            case 1:
                Alexander_Helper(grid,i-1,j-1,row,col,word,iter+1,len,key,pin);
                break;
            case 2:
                Alexander_Helper(grid,i-1,j,row,col,word,iter+1,len,key,pin);
                break;
            case 3:
                Alexander_Helper(grid,i-1,j+1,row,col,word,iter+1,len,key,pin);
                break;
            case 4:
                Alexander_Helper(grid,i,j+1,row,col,word,iter+1,len,key,pin);
                break;
            case 5:
                Alexander_Helper(grid,i+1,j+1,row,col,word,iter+1,len,key,pin);
                break;
            case 6:
                Alexander_Helper(grid,i+1,j,row,col,word,iter+1,len,key,pin);
                break;
            case 7:
                Alexander_Helper(grid,i+1,j-1,row,col,word,iter+1,len,key,pin);
                break;
            case 8:
                Alexander_Helper(grid,i,j-1,row,col,word,iter+1,len,key,pin);
                break;
            default:
                return;
        }
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int len = word.size(), key = 0, iter, row = grid.size(), col = grid[0].size();
	    vector<vector<int>> vec;
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j] == word[0])
	            {
	                iter = 0;
	                key = 0;
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 1);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 2);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 3);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 4);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 5);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 6);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 7);
	                Alexander_Helper(grid, i, j, row, col, word, iter, len, key, 8);
	               // cout<<key<<endl;
	                if(key == 1) vec.push_back({i, j});
	            }
	        }
	    }
	    return vec;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends