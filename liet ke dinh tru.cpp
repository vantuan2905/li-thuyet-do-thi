#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ok[1005],n,m;vector<int> v[1005];
void dfs(int i){
	ok[i]=1;
	for(int j=0;j<v[i].size();j++){
		if(ok[v[i][j]]==0) dfs(v[i][j]);
	}
}
int dem(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ok[i]==0){
			cnt++;dfs(i);
		}
	}
	for(int i=1;i<=n;i++) ok[i]=0;
	return cnt;
}
main(){
	int t;
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int tplt=dem(),cnt=0;
		for(int i=1;i<=n;i++){
			ok[i]=1;
			int k=dem();
			if(k!=tplt) cout<<i<<" ";
		}
		cout<<""<<endl;
	}
}
