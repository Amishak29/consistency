//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
    // Condition when there are no houses
    if (n == 0)
        return 0;
    // Condition when there is only one house
    if (n == 1)
        return arr[0];

    // Taking an extra array with size n
    int dp[n];

    // Initializing the first and second element for two houses
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    // Iterating from the 2nd house to the last house
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }

    return dp[n - 1];
}

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends