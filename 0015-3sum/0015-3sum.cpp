class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicates for 'i'
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    
                    // Skip duplicates for left
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    // Skip duplicates for right
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    
                    left++;
                    right--;
                }
            }
        }
        
        return ans;
    }
};