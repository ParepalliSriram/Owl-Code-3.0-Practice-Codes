//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    int a=arr[0], ind=0, i=1, ma=0;
    while(i<n and arr[i]<a) i++;
    if(i<n)
    {
        ind=i;
        a=arr[i];
    }
    while(i<n)
    {
        if(arr[i]>ma) ma=arr[i];
        if(arr[i] < a)
        {
            while((arr[i]<a or arr[i]<ma) and i<n)
            {
                if(arr[i]>ma) ma=arr[i];
                i++;
            }
            if(i<n-1)
            {
                ind=i;
                a=arr[i];
            }
            else a=-1;
        }
        i++;
        // cout<<a<<"\n";
    }
    if(ind==n-1 or ind==0) a=-1;
    return a;
}