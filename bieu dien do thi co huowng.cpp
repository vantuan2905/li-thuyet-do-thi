#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int d,c;
};
main(){
	int t;
	cin>>t;
	while(t--){
		vector<int > v[1005];
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			cout<<i<<": ";
			for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";cout<<endl;
		}
	}
}
