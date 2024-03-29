class Solution {
public:
     int pivotIndex(vector<int>& nums) {
        int t_sum=0,l_sum=0,r_sum=0,n=nums.size();
        for(int i: nums)
            t_sum+=i;

        for(int i=0;i<n;i++)
        {
            r_sum=t_sum-l_sum-nums[i];
            if(r_sum==l_sum)
                return i;
            else{
                l_sum+=nums[i];
            }
        }
        return -1;
    }
};