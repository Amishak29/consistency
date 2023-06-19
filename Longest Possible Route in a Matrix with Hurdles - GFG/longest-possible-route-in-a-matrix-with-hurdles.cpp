//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
        int n,m;
    
    void solver(vector<vector<int>> &matrix,int &ans,int count,int i,int j,int xd,int yd){
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]==0) return;
        if(i==xd && j==yd){
            ans=max(ans,count);
            return;
        }
        matrix[i][j]=0;
        solver(matrix,ans,count+1,i+1,j,xd,yd);
        solver(matrix,ans,count+1,i-1,j,xd,yd);
        solver(matrix,ans,count+1,i,j+1,xd,yd);
        solver(matrix,ans,count+1,i,j-1,xd,yd);
        matrix[i][j]=1;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int ans=INT_MIN;
        n=matrix.size(),m=matrix[0].size();
        solver(matrix,ans,0,xs,ys,xd,yd);
        if(ans==INT_MIN) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends