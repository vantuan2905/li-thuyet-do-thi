#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];int ok[1005];int truoc[1005];
void dfs(int u){
	ok[u]=1;
	for(int i=0;i<v[u].size();i++) if(ok[v[u][i]]==0){truoc[v[u][i]]=u; dfs(v[u][i]);}
}
main(){
	int t;
	cin>>t;
	while(t--){int s,tt;memset(v,0,sizeof(v));memset(ok,0,sizeof(ok));memset(truoc,0,sizeof(truoc));
		cin>>n>>m>>s>>tt;
		for(int i=1;i<=m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(s);
		if(truoc[tt]==0) cout<<-1<<endl;
		else{stack<int> st;
			while(tt!=0){
				st.push(tt);tt=truoc[tt];
			}
			while(st.size()){
				cout<<st.top()<<" ";st.pop();
			}
			cout<<endl;
		}
	}
}
