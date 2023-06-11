class Solution {
public:
    void solve(vector<vector<int>> &result, vector<int> &nums, int n, int idx){
        
        if(idx == n-1){
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[i], nums[idx]);
            solve(result, nums, n, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        solve(result, nums, n, 0);
     

        return result;
    }
};