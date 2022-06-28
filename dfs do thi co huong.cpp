#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,u;stack<int> st;
		vector<int> v[1005];
		cin>>n>>m>>u;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		st.push(u);int ok[1005]={0};cout<<u<<" ";ok[u]=1;
		while(st.size()){
			int s=st.top();st.pop();
			for(int j=0;j<v[s].size();j++){
				if(ok[v[s][j]]==0){ok[v[s][j]]=1;cout<<v[s][j]<<" ";
					st.push(s);st.push(v[s][j]);break;
				}
			}
		}
		cout<<endl;
	}
}
