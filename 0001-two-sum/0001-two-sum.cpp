class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            res.push_back({nums[i], i});
        }
        
        sort(res.begin(), res.end());
        
        int left = 0;
        int right = res.size() - 1;

        while (left < right) {
            int sum = res[left].first + res[right].first;
            if (sum == target) {
                return {res[left].second, res[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; 
    }
};