#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];
int ok[1005];
void init(){
	for(int i=1;i<=n;i++) ok[i]=0;
}
void dfs(int i){
	stack<int> st;
	st.push(i);ok[i]=1;
	while(st.size()){
		int s=st.top();st.pop();
		for(int j=0;j<v[s].size();j++){
			if(ok[v[s][j]]==0){
				ok[v[s][j]]=1;
				st.push(s);st.push(v[s][j]);break;
			}
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));memset(ok,0,sizeof(ok));
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
				dfs(i);
			}
		}
		cout<<cnt<<endl;
	}
}
