#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	t=1;
	while(t--){
		int n,k,a[2000];
		cin>>n>>k;swap(n,k);
		for(int i=1;i<=n;i++) cin>>a[i];
		int dp[20000]={0};dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=k;j>=0;j--){
				if(dp[j-a[i]]==1) dp[j]=1;
			}
		}
		for(int i=k;i>=0;i--){
			if(dp[i]==1){
				cout<<i<<endl;break;
			}
		}
	}
}
