class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> mp;
    int ans = 0;
    int row = grid.size();
    int col = grid[0].size();
    int i = 0;

    while (i < row) {
        mp[grid[i]]++;
        i++;
    }

    i = 0;
    while (i < col) {
        vector<int> v;
        int j = 0;

        while (j < row) {
            v.push_back(grid[j][i]);
            j++;
        }

        ans += mp[v];
        i++;
    }

    return ans;

    }
};