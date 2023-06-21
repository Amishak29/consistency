//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
    stack<int> st;
    st.push(-1); // Initialize stack with -1
    
    int longestLength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i); // Push the index of opening parenthesis
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop(); // Pop the index of matching opening parenthesis
                if (!st.empty()) {
                    int currentLength = i - st.top();
                    longestLength = std::max(longestLength, currentLength);
                } else {
                    st.push(i); // Push the index of unmatched closing parenthesis
                }
            } else {
                st.push(i); // Push the index of unmatched closing parenthesis (w)
            }
        }
    }
    
    return longestLength;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends