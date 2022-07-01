#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[100005];vector<int> v[100005];int cnt,ans;
void dfs(int i){
	cnt++;
	ok[i]=1;
	for(int j=0;j<v[i].size();j++) if(ok[v[i][j]]==0) dfs(v[i][j]);
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;ans=0;memset(v,0,sizeof(v));memset(ok,0,sizeof(ok));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(ok[i]==0){cnt=0;
				dfs(i);
				ans=max(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
}
