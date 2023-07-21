//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    public:
  string longestPalin (string s) {
        int length=s.size();
        int start=0,end=0,maxl=1;
        for(int i=0;i<length;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<length)
            {
                if(s[l]!=s[r])
                {
                    break;
                }
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>maxl)
            {
                maxl=len;
                start=l+1;
                end=r-1;
            }
        }
        
        //even length
        for(int i=0;i<length;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<length)
            {
                if(s[l]!=s[r])
                {
                    break;
                }
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>maxl)
            {
                maxl=len;
                start=l+1;
                end=r-1;
            }
        }
        
        return s.substr(start,maxl);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends