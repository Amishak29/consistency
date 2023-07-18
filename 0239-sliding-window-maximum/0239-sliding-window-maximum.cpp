class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;

    deque<int> window;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        // Remove elements outside of the current window
        while (!window.empty() && window.front() <= i - k)
            window.pop_front();

        // Remove smaller elements from the back of the window
        while (!window.empty() && nums[window.back()] < nums[i])
            window.pop_back();

        // Add the current element's index to the window
        window.push_back(i);

        // The front element of the window is the maximum for the current window
        if (i >= k - 1)
            result.push_back(nums[window.front()]);
    }

    return result;
}

};