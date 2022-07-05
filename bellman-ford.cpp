#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int d,c;
};
vector<gt> v[1005];
int n,m,d[1005],u;
void bellman(){
	for(int i=1;i<=n;i++) d[i]=1e9;
	for(int i=0;i<v[u].size();i++){
		d[v[u][i].d]=v[u][i].c;
	}
	d[u]=0;
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<v[j].size();k++){
				if(d[v[j][k].d]+v[j][k].c<d[j]){
					d[j]=d[v[j][k].d]+v[j][k].c;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";cout<<endl;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>u;memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			struct gt a,b;
			cin>>a.d>>b.d>>a.c;
			b.c=a.c;
			v[a.d].push_back(b);v[b.d].push_back(a);
		}
		bellman();
	}
}
