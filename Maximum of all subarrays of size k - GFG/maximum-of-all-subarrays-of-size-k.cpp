//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    vector<int> max_of_subarrays(int *arr, int n, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> pq;

    // Insert the first K elements into the priority queue
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(arr[i], i));
    }

    // The maximum element in the current subarray is at the top of the priority queue
    result.push_back(pq.top().first);

    // Process the remaining subarrays
    for (int i = k; i < n; i++) {
        // Remove the elements that are outside the current subarray window
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        // Insert the current element into the priority queue
        pq.push(make_pair(arr[i], i));

        // The maximum element in the current subarray is at the top of the priority queue
        result.push_back(pq.top().first);
    }

    return result;
}
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends