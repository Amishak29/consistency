class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int i = 0; i < nums.size(); i++){
            counter[nums[i]]++;
        }
        for(auto it: counter){
            if(it.second > nums.size() / 2){
                return it.first;
            }
        }
        return -1; 
    }
};
