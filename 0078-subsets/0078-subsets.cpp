class Solution {
public:
     
void generateSubsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(subset);
        return;
    }

    generateSubsets(index + 1, nums, subset, result);
    subset.push_back(nums[index]);
    generateSubsets(index + 1, nums, subset, result);
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    generateSubsets(0, nums, subset, result);
    return result;
}
};