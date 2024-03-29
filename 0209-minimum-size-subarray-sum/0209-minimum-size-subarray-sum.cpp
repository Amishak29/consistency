class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};

// //while(r<n){
//             sum+=arr[r++];
//             while(sum>=k){
//                sum-=arr[l++];
//                mini=min(mini,r-l+1); //will remove remaining left element and storing minimum index among them
//             }
//         }
//         if(mini<INT_MAX)
//         return mini;
//         else return 0;