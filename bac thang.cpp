#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;int m=1e9+7;
		int dp[1000]={0};dp[0]=dp[1]=1;
		for(int i=2;i<=k;i++){
			for(int j=0;j<i;j++){ dp[i]+=dp[j];dp[i]%=m;}
		}
		for(int i=k+1;i<=n;i++){
			for(int j=i-k;j<i;j++){ dp[i]+=dp[j];dp[i]%=m;}
		}
		cout<<dp[n]<<endl;
	}
}
