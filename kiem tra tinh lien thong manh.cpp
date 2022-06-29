#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];int ok[1005];
void init(){
	for(int i=1;i<=n;i++) ok[i]=0;
}
void dfs(int i){
	ok[i]=1;
	for(int j=0;j<v[i].size();j++) if(ok[v[i][j]]==0) dfs(v[i][j]);
}
int solve(){
	for(int i=1;i<=n;i++){
		int cnt=0;init();
		dfs(1);
		for(int j=1;j<=n;j++) if(ok[i]==0) cnt++;
		if(cnt!=0) return 0;
	}
	return 1;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		int kt=solve();
		if(kt) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
}
