class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> arr[n+m];
        int temp=n+m-1;
        int i=m-1;
        int j=n-1;
        // int t;
        while(j>=0){
            if(i>=0&& nums1[i]>=nums2[j]){
                nums1[temp]=nums1[i];
                temp--;
                i--;
            }
            else{
                nums1[temp]=nums2[j];
                temp--;
                j--;
            }
        }
        
    }
};