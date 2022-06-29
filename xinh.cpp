#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> v[1005];
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){ //cout<<v[i].size()<<"  ";
			if(v[i].size()%2==1) cnt++;
		}
		if(cnt==0||cnt==2){
			if(cnt==2) cout<<1<<endl;
			else cout<<2<<endl;
		}
		else cout<<"0\n";
	}
}
