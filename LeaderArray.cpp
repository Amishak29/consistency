// Write a cpp program to print all the LEADERS in the array.

// Note: An element is leader if it is greater than all the elements to its right side
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int j;
    for(int i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]<=arr[j]){
                // cout<<arr[i];
                break;
            }
        }
        if(j==n){
            cout<<arr[i]<<" ";
        }
        // break;
    }
}    