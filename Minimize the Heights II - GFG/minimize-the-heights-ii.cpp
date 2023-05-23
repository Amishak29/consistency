//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
         sort(arr,arr+n);
         int miny;
         int maxy;
         int ans= arr[n-1]-arr[0];
         for(int i=0;i<n;i++){
            //  if(arr[i]-k<0){
            //      continue;
            //  }
             maxy=max(arr[i-1]+k,arr[n-1]-k);
             miny=min(arr[0]+k,arr[i]-k);
             ans=min(ans,maxy-miny);
         }
         return ans;
    }
};

//1 3 5 7 9 11   k=3
// 4 6 8 ||


//partitioning is done from i
// 1 4 4 5 5 6 7 7 8 9
// 6 9 9 11 11 1 2 2 3 4 

//

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends