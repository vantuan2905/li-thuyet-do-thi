#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[1005];int b[1005];vector<int> v[1005];int kt;
void hmt(int i){
	if(i==n+1){
		kt=1;return;
	}
	for(int j=0;j<v[b[i-1]].size();j++){
		if(ok[v[b[i-1]][j]]==0){
			b[i]=v[b[i-1]][j];
			ok[v[b[i-1]][j]]=1;
			hmt(i+1);
			ok[v[b[i-1]][j]]=0;
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		} kt=0;
		for(int i=1;i<=n;i++){
			b[1]=i;
			ok[i]=1;
			hmt(2);
			ok[i]=0;
		}
		if(kt) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
