class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size(),k,l;

        for(k = n-2;k>=0;k--)       //iterte from back ... min 2 element in array coz ek element ho toh answer toh same hi                                      //hoga of that element
        {
            if(nums[k] < nums[k+1])
            {
                break;
            }
        }

        if(k<0)      //for edge case no break point
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l = n-1 ; l >=k ; l--)
            {
                if(nums[l] > nums[k])
                {
                    break;
                }
            }

            swap(nums[k], nums[l]);

            reverse(nums.begin()+k+1,nums.end());
        }
    }
    
};