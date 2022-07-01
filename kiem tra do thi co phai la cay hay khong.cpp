#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,ok[1005]={0};vector<int> v[1005];
		cin>>n;m=n-1;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		stack<int> st;
		st.push(1);ok[1]=1;
		while(st.size()){
			int s=st.top();st.pop();
			for(int j=0;j<v[s].size();j++){
				if(ok[v[s][j]]==0){
					ok[v[s][j]]=1;
					st.push(s);st.push(v[s][j]);
				}
			}
		}
		int kt=0;
		for(int j=1;j<=n;j++) if(ok[j]==0) kt=1;
		if(m==n-1&&kt==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
