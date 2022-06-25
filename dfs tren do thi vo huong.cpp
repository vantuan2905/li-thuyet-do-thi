#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> v[1005];
		int n,m,s;
		cin>>n>>m>>s;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		stack<int> st;
		st.push(s);cout<<s<<" ";
		int ok[2000]={0};
		ok[s]=1;
		while(st.empty()==0){
			int tmp=st.top();st.pop();
			for(int j=0;j<v[tmp].size();j++){
				if(ok[v[tmp][j]]==0){
					ok[v[tmp][j]]=1;cout<<v[tmp][j]<<" ";
					st.push(tmp);st.push(v[tmp][j]);break;
				}
			}
		}
		cout<<endl;
	}
}
