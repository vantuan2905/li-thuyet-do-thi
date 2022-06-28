#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,s,tt;
		queue<int> q;vector<int> v[1005];
		cin>>n>>m>>s>>tt;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		int ok[1005]={0},truoc[1005]={0};
		q.push(s);ok[s]=1;truoc[s]=0;
		while(q.size()){
			int x=q.front();q.pop();
			for(int i=0;i<v[x].size();i++){
				if(ok[v[x][i]]==0){q.push(v[x][i]);
					truoc[v[x][i]]=x;ok[v[x][i]]=1;
				}
			}
		}
		stack<int> st;
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
