class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        long currsum=0;
      long maxsum=LONG_MIN;
        for(int i=0;i<n;i++){
            currsum+=arr[i];
            if(currsum>maxsum){
                maxsum=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
    
};