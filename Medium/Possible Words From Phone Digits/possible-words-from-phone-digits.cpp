//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> key={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void Helper(int a[], int N, int i, vector<string> &vec, string s)
    {
        if(i>=N)
        {
            vec.push_back(s);
            return;
        }
        for(int j=0;j<key[a[i]].size();j++) Helper(a, N, i+1, vec, s+key[a[i]][j]);
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> vec;
        Helper(a, N, 0, vec, "");
        return vec;
        //Your code here
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends