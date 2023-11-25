class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        int pref=accumulate(arr.begin(),arr.end(),0),diff=0;
        for(int i=0;i<n;i++){
            int res=abs(pref-(n-i)*arr[i]+(i)*arr[i]-diff);
            pref-=arr[i];
            diff+=arr[i];
            ans.push_back(res);
        }
        return ans;
    }
};