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
    for(int i=index;i<n;i++){
        if(ispalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            partioning(s,i+1,n,path);
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