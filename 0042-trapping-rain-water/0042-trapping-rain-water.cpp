class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=height[0], rightMax=height[n-1];
        int left = 1, right = n-2;
        int ans=0;
        while(left <= right)
        {
            if(leftMax < rightMax)
            {
                if(height[left]>=leftMax)
                {
                    leftMax=height[left];
                }
                else
                {
                    ans+=leftMax-height[left];
                }
                left++;
            }
            else
            {
                if(rightMax<=height[right])
                {
                    rightMax=height[right];
                }
                else
                {
                    ans+=rightMax-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};