class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());

    vector<int> intersection;
    for (int num : arr2) {
        if (set1.count(num) > 0) {
            intersection.push_back(num);
            set1.erase(num); // Remove the element to handle duplicates
        }
    }

    return intersection;
    }
};