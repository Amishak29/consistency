//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
             map<int,int> m;
            for(int i=0; i<n1; i++) {
                if(a[i]==a[i-1])
                continue;
                m[a[i]]++;
            }
            for(int i=0; i<n2; i++) {
                if(b[i]==b[i-1])
                continue;
                m[b[i]]++;
            }
            for(int i=0; i<n3; i++) {
                if(c[i]==c[i-1])
                continue;
                m[c[i]]++;
            }
            vector<int> v;
            for(auto i : m) {
                if(i.second>2) {
                    v.push_back(i.first);
                }
            }
            if(v.empty()) {
                return {-1};
            }
            return v;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends