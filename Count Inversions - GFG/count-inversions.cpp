//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
     #define ll long long 
    ll merge(long long arr[], ll low, ll mid, ll high,ll N) {
    vector<ll int> temp; // temporary array
    ll left = low;      // starting index of left half of arr
    ll right = mid + 1;   // starting index of right half of arr
    ll cnt = 0 ;
    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { //right smaller 
            
            temp.push_back(arr[right]);
            cnt += (mid - left +1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

ll mergeSort(long long arr[], ll low, ll high ,ll N) {
    ll cnt = 0 ;
    if (low >= high) return cnt;
    ll mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid,N);  // left half
    cnt += mergeSort(arr, mid + 1, high,N); // right half
    cnt +=  merge(arr, low, mid, high,N);
    return cnt;  // merging sorted halves
}
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1,N);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends