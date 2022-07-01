#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[1005];vector<int> v[1005];
void dfs(int i){
	ok[i]=1;
	for(int j=0;j<v[i].size();j++) if(ok[v[i][j]]==0) dfs(v[i][j]);
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));memset(ok,0,sizeof(ok));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1);int kt=1;
		for(int i=1;i<=n;i++) if(ok[i]==0) kt=0;
		if(kt==0) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
