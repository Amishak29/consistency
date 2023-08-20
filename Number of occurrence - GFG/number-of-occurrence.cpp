//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
        // code here
        
        int low=0, high=n-1, count=0;
        int mid = (low+high)/2;
    
        while(low<=high){ 
            if (arr[mid]==x){
                count++;
                break;
            } else if (arr[mid]>x){
                high=mid-1;
                mid = (low+high)/2;
            } else {
                low=mid+1;
                mid = (low+high)/2;
            }
        }
        
        for (int i = mid-1; i>=0; i--){
                if (arr[i]==x)
                    count++;
                if(arr[i]!=x)
                    break;
            }
       
       for (int i = mid+1; i<n; i++){
                if (arr[i]==x)
                    count++;
                if (arr[i]!=x)
                    break;    
            }
        
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends