class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string ans = "";
        // sort(strs.begin(),strs.end());
        if(strs.empty()){
           return ans;
        }
        if(strs.size()==1){
           return strs[0];
        }
        for(int i=0;i<strs[0].size();i++){
           char ch = strs[0][i];
            bool match =true;
            for(int j=1;j<strs.size();j++){
                if(ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }
            if(match ==false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};