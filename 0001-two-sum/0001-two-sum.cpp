class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the numbers we've seen so far.
        unordered_map<int, int> seen;

        // Loop through the input vector 'nums'.
        for (int i = 0; i < nums.size(); ++i) {
            int b = nums[i];         // Get the current number 'b' from the vector.
            int a = target - b;     // Calculate the number 'a' needed to reach the target.

            // Check if we've already seen 'a' in the 'seen' map.
            if (seen.count(a)) {
                // If we've seen 'a' before, it means we've found a pair (a, b)
                // where a + b equals the 'target'. Return the indices of 'a' and 'b'.
                return {seen[a], i};
            }

            // If we haven't seen 'a' yet, store the current number 'b' along with its index 'i'
            // in the 'seen' map for future reference.
            seen[b] = i;
        }

        // If no pair is found, return an empty vector to indicate failure.
        return {};
    }
};
