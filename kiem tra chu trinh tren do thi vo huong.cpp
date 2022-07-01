#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[1005];vector<int> v[1005];int kt,c;
void dfs(int i,int cnt){
	ok[i]=1;
	if(kt==1) return;
	if(cnt>1){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]==c){ kt=1;}
		}
	}
	if(kt==1) return;
	for(int j=0;j<v[i].size();j++){
		if(ok[v[i][j]]==0) dfs(v[i][j],cnt+1);
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));//memset(ok,0,sizeof(ok));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		} kt=0;
		for(int i=1;i<=n&&kt==0;i++){ memset(ok,0,sizeof(ok));
			c=i;
			dfs(i,0);
		}
		if(kt==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
