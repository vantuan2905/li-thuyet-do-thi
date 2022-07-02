#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,u,ok[1005];vector<int> v[1005],ans[1005];int cnt;
void dfs(int i){
	ok[i]=1;
	for(int j=0;j<v[i].size();j++){
		if(ok[v[i][j]]==0){
			ans[cnt].push_back(i);ans[cnt].push_back(v[i][j]);cnt++;
			dfs(v[i][j]);
		}
	}
}
void bfs(int i){
	ok[i]=1;
	queue<int> q;
	q.push(i);
	while(q.size()){
		int s=q.front();q.pop();
		for(int j=0;j<v[s].size();j++){
			if(ok[v[s][j]]==0){
				ok[v[s][j]]=1;
				ans[cnt].push_back(s);ans[cnt].push_back(v[s][j]);
				cnt++;
				q.push(v[s][j]);
			}
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>u;cnt=0;memset(ok,0,sizeof(ok));memset(v,0,sizeof(v));memset(ans,0,sizeof(ans));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bfs(u);
		if(cnt==n-1){
			for(int i=0;i<cnt;i++) cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
		}else cout<<-1<<endl;
	}
}
