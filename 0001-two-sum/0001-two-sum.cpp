class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> ans(2);
        for(i=0;i<nums.size();i++){
        for(j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                //ans.push_back(i);
                //ans.push_back(j);
                ans[0]=i;
                ans[1]=j;
            }            
        }
        
    }
        return ans;
    }
};