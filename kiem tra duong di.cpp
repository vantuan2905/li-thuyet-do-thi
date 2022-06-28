#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ok[1005],truoc[1005];vector<int> v[1005];
int init(){
	for(int i=1;i<=n;i++) truoc[i]=ok[i]=0;
}
void dfs(int u){
	stack<int> st;
	st.push(u);ok[u]=1;
	while(st.size()){
		int s=st.top();st.pop();
		for(int i=0;i<v[s].size();i++){
			if(ok[v[s][i]]==0){
				st.push(s);st.push(v[s][i]);truoc[v[s][i]]=s;ok[v[s][i]]=1;break;
			}
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);v[y].push_back(x);
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			init();
			int a,b;
			cin>>a>>b;
			dfs(a);
			if(truoc[b]==0) cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}
