class Solution {
public:
       long long largestPerimeter(vector<int>& A) {
        long long cur = accumulate(A.begin(), A.end(), 0L);
        priority_queue<int> maxHeap(A.begin(), A.end());
        while (!maxHeap.empty() && cur <= maxHeap.top() * 2) {
            cur -= maxHeap.top();
            maxHeap.pop();
        }
        return cur > 0 && maxHeap.size() >= 2 ? cur : -1;
    }
};