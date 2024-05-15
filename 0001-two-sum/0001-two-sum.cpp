class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back({nums[i], i});
        }
        sort(res.begin(), res.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (res[left].first + res[right].first == target) {
                return {res[left].second, res[right].second};
            } else if (res[left].first + res[right].first < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
