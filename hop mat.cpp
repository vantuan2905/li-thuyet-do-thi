#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k;int ok[1005];int c;
vector<int> v[1005],ans[1005];
void dfs(int i){ //cout<<i<<" ";
	ok[i]=1;ans[i].push_back(c);
	for(int j=0;j<v[i].size();j++){
		if(ok[v[i][j]]==0){
			dfs(v[i][j]);
		}
	}
}
main(){
	int t;
	t=1;
	while(t--){int ds[200];
		cin>>k>>n>>m;
		for(int i=0;i<k;i++) cin>>ds[i];
		for(int j=0;j<m;j++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		} int cnt=0;
		for(int i=0;i<k;i++){
			c=ds[i];memset(ok,0,sizeof(ok));
		//	ans[c].push_back(c);
			dfs(ds[i]);
		}
		for(int i=1;i<=n;i++){
			
			if(ans[i].size()==k) cnt++;
		}
		cout<<cnt<<endl;
	}
}
