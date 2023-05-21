class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map <int, int> m;
        int b=0;
        for(auto i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>1){
                b=i.first;
                break;
            }
        }
        return b;
    }
};