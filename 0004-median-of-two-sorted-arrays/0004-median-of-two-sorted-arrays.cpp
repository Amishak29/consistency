class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //         vector<int>v;
    //         for(auto num:nums1)   // O(n1)
    //             v.push_back(num); //       
    //for(auto num:nums2)  // O(n2)
    //             v.push_back(num);
        //         sort(v.begin(),v.end());  // O(nlogn)
        //         int n=v.size();  // O(n)
        //         return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    if (nums1.size() > nums2.size()) {
        nums1.swap(nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int start = 0;
    int end = m;

    while (start <= end) {
        int partitionX = (start + end) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int leftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int rightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        int leftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int rightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (leftX <= rightY && leftY <= rightX) {
            if ((m + n) % 2 == 0) {
                return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
            } else {
                return max(leftX, leftY);
            }
        } else if (leftX > rightY) {
            end = partitionX - 1;
        } else {
            start = partitionX + 1;
        }
    }

    // If the control reaches here, the arrays are not sorted or there is an error in the input
    throw invalid_argument("Arrays are not sorted or invalid input.");
}
};