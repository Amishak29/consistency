#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map< char, int> arr;
        
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;
        
        int temp =0;
        
        for(int i =0; i<s.length(); i++){
            if( arr[s[i]] < arr[s[i+1]])
                temp = temp - arr[s[i]];
            else
                temp = temp + arr[s[i]];
        }
        cout<<temp;
}