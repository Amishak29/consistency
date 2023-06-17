
   class Solution {
public:
    bool solve(int i,int j,int k,int &m,int &n,vector<vector<int>> &g){
        if(i<0||j<0||i>=m||j>=n||g[i][j] != k)return false;
        if(k==m*n-1)return true;
        return solve(i+2,j-1,k+1,m,n,g)||solve(i+2,j+1,k+1,m,n,g)||solve(i-2,j-1,k+1,m,n,g)||solve(i-2,j+1,k+1,m,n,g)||solve(i-1,j-2,k+1,m,n,g)||solve(i-1,j+2,k+1,m,n,g)||solve(i+1,j+2,k+1,m,n,g)||solve(i+1,j-2,k+1,m,n,g);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int x = 0,m=grid.size(),n=grid[0].size();
        return solve(0,0,0,m,n,grid);
    }

};