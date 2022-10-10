// Write a cpp program to find the length of the longest sequence of zeros in binary representation of an integer.

// Sample example:
// Number 7 has binary representation 111 and has no binary gaps.
// Number 8 has binary representation 1000 and contains a binary gap of length 0.
// Number 457 has binary representation 111001001 and contains a binary gap of length 2.
// Number 40 has binary representation 101000 and contains one binary gap of length 1.
// Number 12546 has binary representation 11000100000010 and contains highest binary gap of length 6.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[100], n, i;    

    cin>>n;    
    for(i=0; n>0; i++)    
    {    
    arr[i]=n%2;    
    n= n/2;  
    }    
 
    // for(i=i-1 ;i>=0 ;i--)    
    // {    
    // cout<<arr[i];    
    // } 
        int a = 0;
        int count = 0;
        for(int i = 0 ; i < 100 ; i++) {
            if(arr[i] == 0)
                count++;
            else
                count = 0;
            a = max(a,count);
        }
        cout<<a<<endl;
  }
