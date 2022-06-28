#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,s,tt;vector<int> v[1005];
		cin>>n>>m>>s>>tt;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		stack<int> st;int ok[1005]={0};
		st.push(s);int truoc[1005]={0};ok[s]=1;truoc[s]=0;
		
		while(st.size()){
			int u=st.top();st.pop();
			for(int i=0;i<v[u].size();i++){ //cout<<v[u][i]<<" ";
				if(ok[v[u][i]]==0){//cout<<v[u][i]<<' '<<u<<endl;
					truoc[v[u][i]]=u;st.push(u);st.push(v[u][i]);ok[v[u][i]]=1;break;
				}
			}
		}
		//st.push(tt);
		if(truoc[tt]==0){
			cout<<-1<<endl;continue;
		}
		while(tt!=0){
			st.push(tt);tt=truoc[tt];
		}
		while(st.size()){
			cout<<st.top()<<" ";st.pop();
		}cout<<endl;
	}
}
