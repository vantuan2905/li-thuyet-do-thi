#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];int ok[1005];
void bfs(int i){
	queue<int> q;
	q.push(i);ok[i]=1;
	while(q.size()){
		int s=q.front();q.pop();
		for(int j=0;j<v[s].size();j++){
			if(ok[v[s][j]]==0){
				q.push(v[s][j]);ok[v[s][j]]=1;
			}
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){memset(ok,0,sizeof(ok));memset(v,0,sizeof(v));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ok[i]==0){
				cnt++;
				bfs(i);
			}
		}
		cout<<cnt<<endl;
	}
}
