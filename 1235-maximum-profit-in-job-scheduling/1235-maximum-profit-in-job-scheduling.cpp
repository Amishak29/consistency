class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& p) {
        int n=start.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
            v.push_back({end[i],start[i],p[i]});
        sort(v.begin(),v.end()); 
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
             dp[i]=v[i][2];
            if(i==0)
            {
                ans=max(ans,dp[i]);continue;
            }
            dp[i]=max(dp[i],dp[i-1]);
            int curr=v[i][1];
            for(int j=i-1;j>=0;j--)
            {
                if(v[j][0]<=curr)
                {
                     dp[i]=max(dp[i],dp[j]+v[i][2]);break;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};