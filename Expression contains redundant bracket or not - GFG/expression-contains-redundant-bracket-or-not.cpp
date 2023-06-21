//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkRedundancy(string& str)
{
	stack<char> st;

	for (auto& ch : str) {

		if (ch == ')') {
			char top = st.top();
			st.pop();

			bool flag = true; //there are redundant brackets

			while (!st.empty() and top != '(') {

				// Check for operators in expression
				if (top == '+' || top == '-' ||
					top == '*' || top == '/')
					flag = false;

				top = st.top();
				st.pop();
			}

			if (flag == true)
				return true; // there are redundant brackets
		}

		else
			st.push(ch); 
	}
	return false;
}

void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends