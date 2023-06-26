//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
   
public:

vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3) {
unordered_map<int, int> m1, m2, m3;
for(int i = 0; i < n1; i++) {
    m1[a[i]]++;
}
for(int i = 0; i < n2; i++) {
    m2[b[i]]++;
}
for(int i = 0; i < n3; i++) {
    m3[c[i]]++;
}
vector<int> v;
for(int i = 0; i < n1; i++) {
    if(m1[a[i]] > 0 && m2[a[i]] > 0 && m3[a[i]] > 0) {
        v.push_back(a[i]);
        m1[a[i]] = 0; // Marking the element as processed to avoid duplicates
    }
}

return v;
// vector<int> result;

// int i = 0, j = 0, k = 0;
// while (i < n1 && j < n2 && k < n3) {

//     if (A[i] == B[j] && B[j] == C[k]) {

//         if (result.empty() || result.back() != A[i]) {
//             result.push_back(A[i]);
//         }
//         i++; j++; k++;
//     }
//     // If the current element in A is smaller than the other two arrays
//     else if (A[i] < B[j])
//         i++; // Move pointer in A ahead

//     else if (B[j] < C[k])
//         j++;

//     else
//         k++;
// }

// return result;
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