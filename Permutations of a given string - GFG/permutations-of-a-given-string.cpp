//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		  vector<string>find_permutation(string S)
        {
            vector<string> ans;
            if (S.size()==1){
                ans.push_back(S);
                return ans;
            }
            
            sort(S.begin(), S.end());
            
            for (int i=0; i<=S.size()-1;++i){
                if (i > 0 && S[i] == S[0]) {
                continue; // Skip swapping duplicate characters
                }
                swap(S[0], S[i]);
                string subStr = S.substr(1);
                vector<string>subString = find_permutation(subStr);
                
                for ( auto  ele:subString){
                    
                    string s= S[0]+ ele;
                    ans.push_back(s);
                }
            }          
            return ans;
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends