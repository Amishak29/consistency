//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
// arr: input array
// n: size of array
//Function to find the sum of contiguous subarray with maximum sum.
long long maxSubarraySum(int arr[], int n){
long currsum=0;
  long maxsum=LONG_MIN;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum>maxsum){
            maxsum=currsum;
        }
        if(currsum<0){
            currsum=0;
        }
    }
    return maxsum;
}
    // long long maxsum = arr[0];
    // long long cursum = arr[0];
    // for (int i = 1; i < n; i++) {
    //     cursum += arr[i];
    //     if (arr[i] > cursum) {
    //         cursum = arr[i];
    //     }
    //     if (cursum > maxsum) {
    //         maxsum = cursum;
    //     }
    // }
    // return maxsum;

    //     }

};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends