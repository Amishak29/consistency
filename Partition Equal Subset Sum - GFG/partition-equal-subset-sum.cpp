//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = accumulate(arr,arr+n,0);
        if(sum % 2 != 0) return false;
        sum=sum/2;
        long long int ss=0;
        int arr2[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0){
                    arr2[i][j]=1;
                }
                else if(i==0){
                    arr2[i][j]=0;
                }
            }
        }
// If the current element arr[i-1] is less than or equal to the target sum j, it means the element can be included. In that case, the maximum of two possibilities is taken:
// Excluding the current element: arr2[i-1][j]
// Including the current element: arr2[i-1][j-arr[i-1]]
// The maximum value is stored in arr2[i][j].
// If the current element arr[i-1] is greater than the target sum j, it means the element cannot be included. In that case, the value from the previous row is copied to arr2[i][j].
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if(arr[i-1]<=j){
                    arr2[i][j]=max(arr2[i-1][j-arr[i-1]],arr2[i-1][j]);
                }
                else{
                    arr2[i][j]=arr2[i-1][j];
                }
            }
        }
        return arr2[n][sum];
        
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends