//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string &A){
    // Code here
    string ans = ""; // Initialize an empty string to store the answer
    queue<char> q; // Create a queue to maintain the order of characters
    unordered_map<char,int> mp; // Create an unordered map to store character frequency

    for(auto &k : A){
        mp[k]++; // Increment the frequency of the current character
        q.push(k); // Push the current character into the queue

        while(!q.empty()){
            if(mp[q.front()] > 1)
                q.pop(); // If the front character has a frequency greater than 1, remove it from the queue
            else {
                ans.push_back(q.front()); // Append the first non-repeating character to the answer string
                break;
            }
        }

        if(q.empty())
            ans.push_back('#'); // If the queue becomes empty, it means there are no non-repeating characters, so append '#' to the answer
    }

    return ans; // Return the final answer string
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends