//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>> ans;
bool ispalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++;
        end--;
    }
    return true;
}
void partioning(string s,int index,int n,vector<string> &path){
    if(index==n){
        ans.push_back(path);
        return;
    }
    for (int i = index; i < n; i++) {
    // Check if the substring from index to i is a palindrome
    if (ispalindrome(s, index, i)) {
        // If it's a palindrome, add it to the current partition
        path.push_back(s.substr(index, i - index + 1));

        // Recursively call the function for the rest of the string
        partioning(s, i + 1, n, path);

        // After the recursive call returns, remove the last added substring
        // This is done to explore other possible partitions
        path.pop_back();
    }
}

}
vector<vector<string>> allPalindromicPerms(string S) {
    vector<string> path;
    partioning(S,0,S.length(),path);
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends