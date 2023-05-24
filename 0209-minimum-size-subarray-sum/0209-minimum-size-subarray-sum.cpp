class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n=arr.size();
           int l=0,r=0;
        int sum=0;
        int mini=INT_MAX;
        while(r<n){
            sum+=arr[r++];
            while(sum>=k){
               sum-=arr[l++];
               mini=min(mini,r-l+1);
            }
        }
        if(mini<INT_MAX)
        return mini;
        else return 0;
    
    }
};