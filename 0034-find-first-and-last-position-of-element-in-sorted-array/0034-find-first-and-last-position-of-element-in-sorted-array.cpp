class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int n = nums.size();
        int first = -1;
        int second = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                second = i;
            }
        }
        return {first, second};
    }
};