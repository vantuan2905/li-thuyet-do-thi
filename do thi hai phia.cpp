#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,color[1005];vector<int> v[1005];
int bfs(int u){
	queue<int> q;
	q.push(u);
	color[u]=1;
	while(q.size()){
		int s=q.front();q.pop();
		for(int i=0;i<v[s].size();i++){
			if(color[v[s][i]]==1-color[s]){
				continue;
			}
			if(color[v[s][i]]==-1){
				color[v[s][i]]=1-color[s];q.push(v[s][i]);
			}else return 0;
		}
	}
	return 1;
}
main(){
	int t;
	cin>>t;
	while(t--){int ok=1;
		cin>>n>>m;fill(color,color+n,-1);memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(color[i]==-1){
				if(bfs(i)==0) {
					ok=0;break;
				}
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
