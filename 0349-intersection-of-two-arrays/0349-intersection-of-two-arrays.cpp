class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());

    vector<int> intersection;
    for (int num : arr2) {
    if (set1.find(num) != set1.end()) {
        intersection.push_back(num);
        set1.erase(num);
    }
}

    return intersection;
    }
};