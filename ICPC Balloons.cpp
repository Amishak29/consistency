#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,res;
		cin>>n;
		res = n+1;
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		for(int i = 0;i<n-1;i++){
			if(s[i] != s[i+1]){
				res++;
			}
		}
		cout<<res<<endl;
	}
}