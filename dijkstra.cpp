#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,u;
struct gt{
	int d,c;
};
vector<gt> v[1005];int truoc[1005],d[1005];
void dijkstra(){
	int ok[1005]={0};d[u]=0;
	for(int i=1;i<=n;i++) d[i]=1e9;d[u]=0;
	for(int i=0;i<v[u].size();i++){
		//cout<<v[u][i].d<<" "<<v[u][i].c<<endl;
		d[v[u][i].d]=v[u][i].c;
	}
	while(1){
		int kt=-1,min=1e9;
		for(int i=1;i<=n;i++){
			if(min>d[i]&&ok[i]==0){
				min=d[i];kt=i;
			}
		}
		if(kt==-1) break;
		ok[kt]=1;
		for(int j=0;j<v[kt].size();j++){
			if(ok[v[kt][j].d]==0&&min+v[kt][j].c<d[v[kt][j].d]){
				d[v[kt][j].d]=min+v[kt][j].c;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";cout<<endl;return;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>u;memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			gt g,g1;
			cin>>g1.d>>g.d>>g.c;g1.c=g.c;v[g1.d].push_back(g);v[g.d].push_back(g1);
		}
		dijkstra();
	}
}
