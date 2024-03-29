//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code 
	    long mx, mi, ans;
            ans = mx = mi = nums[0];
            for (int i=1; i<n; i++)
            {
                long long val=nums[i];
                if (val < 0)
                {
                    swap(mx, mi);
                }

                mi = min(val *mi, val);
                mx = max(val *mx, val);

                ans = max(ans, mx);
            }
            return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends