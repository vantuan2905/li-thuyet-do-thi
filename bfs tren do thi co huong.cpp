#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,u;queue<int> q;
		vector<int> v[1005];
		cin>>n>>m>>u;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		q.push(u);int ok[1005]={0};ok[u]=1;cout<<u<<" ";
		while(q.size()){
			int s=q.front();q.pop();
			for(int i=0;i<v[s].size();i++){
				if(ok[v[s][i]]==0){
					ok[v[s][i]]=1;
					cout<<v[s][i]<<" ";q.push(v[s][i]);
				}
			}
		}cout<<endl;
	}
}
