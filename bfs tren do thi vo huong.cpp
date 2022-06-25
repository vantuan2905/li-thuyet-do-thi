#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,s;
		cin>>n>>m>>s;
		vector<int> v[1005];
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ok[1005]={0};queue<int> q;
		q.push(s);ok[s]=1;cout<<s<<" ";
		while(q.size()){
			int p=q.front();q.pop();
			for(int i=0;i<v[p].size();i++){
				if(ok[v[p][i]]==0){
					ok[v[p][i]]=1;cout<<v[p][i]<<" ";
					q.push(v[p][i]);
				}
			}
		}
		cout<<endl;
	}
}
