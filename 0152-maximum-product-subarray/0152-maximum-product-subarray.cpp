class Solution {
public:
    int maxProduct(vector<int>& nums) {
     long mx, mi, ans;
            ans = mx = mi = nums[0];
            for (int i=1; i<nums.size(); i++)
            {
                long long val=nums[i];
                if (val < 0)
                {
                    swap(mx, mi);
                }

                mi = min(val *mi, val);
                mx = max(val *mx, val);

                ans = max(ans, mx);
            }
            return ans;

    }
};