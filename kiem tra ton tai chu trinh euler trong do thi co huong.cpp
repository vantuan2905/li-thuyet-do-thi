#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> v[1005];int deg[1005]={0};
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);deg[b]++;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(v[i].size()!=deg[i]) cnt++;
		}
		if(cnt!=0) cout<<0<<endl;
		else cout<<1<<endl;
	}
}
