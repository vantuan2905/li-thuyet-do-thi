#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int d,c;
};
int n,m;vector<gt> v[1005];
int ok[1005];
void prime(){
	int h=0;
	ok[1]=1;
	vector<int> vv,vh;vv.push_back(1);ok[1]=1;int cnt=0;
	while(cnt<n-1){
		int kt=1,min=1e9,n1,n2;
		for(int i=0;i<vv.size();i++){
			int s=vv[i];//cout<<s<<" ";
			for(int j=0;j<v[s].size();j++){ //cout<<v[s][j].d<<" ";
				if(ok[v[s][j].d]==0&&min>v[s][j].c){
					min=v[s][j].c;n1=s;n2=v[s][j].d;kt=0;
				}
			}
		}cout<<endl;
		if(kt==1) break;
		h+=min;vv.push_back(n2);ok[n2]=1;
	}
	cout<<h<<endl;
}
main(){
	int t;
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		memset(ok,0,sizeof(ok));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			gt g1,g;
			cin>>g1.d>>g.d>>g.c;g1.c=g.c;
			v[g1.d].push_back(g);
			v[g.d].push_back(g1);
		}
		prime();
	}
}
