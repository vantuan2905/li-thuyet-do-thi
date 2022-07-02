#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[1005];vector<int> v[1005];int kt,c,truoc[1005];
void dfs(int i,int cnt){
	ok[i]=1;//cout<<i;
	if(kt==1) return;
	if(cnt>1){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]==1){truoc[1]=i;
				kt=1;return;
			}
		}
	}
	for(int j=0;j<v[i].size();j++){
		if(ok[v[i][j]]==0){ //cout<<v[i][j]<<" ";
		truoc[v[i][j]]=i;
			dfs(v[i][j],cnt+1);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;kt=1;
		memset(v,0,sizeof(v));memset(ok,0,sizeof(ok));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
		kt=0;c=1;
		dfs(c,0);
		stack<int> st;
		if(kt==0){
			cout<<"NO"<<endl;continue;
		}
		int tt=truoc[1];st.push(1);
		while(tt!=1){
			st.push(tt);tt=truoc[tt];//cout<<tt<<" ";
		}
		st.push(1);
		while(st.size()){
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}
}
