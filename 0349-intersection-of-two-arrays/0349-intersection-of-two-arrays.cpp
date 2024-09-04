class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        
        for (int i = 0; i < arr1.size(); i++) {
            int element = arr1[i];
            for (int j = 0; j < arr2.size(); j++) {
                if (arr2[j] == element) {
                    ans.push_back(arr2[j]);
                    arr2[j] = INT_MIN; 
                    break;
                }
            }
            arr1[i] = INT_MAX; 
        }

        unordered_set<int> uniqueElements(ans.begin(), ans.end());
        return vector<int>(uniqueElements.begin(), uniqueElements.end());
    }
};
