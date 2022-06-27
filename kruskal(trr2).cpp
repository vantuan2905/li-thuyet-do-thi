#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int d,c,m;
};
int n,a[200][200],e; gt ds[2000],k[2000];int ne=0,b[200][200]={0},ok[2000];

void dfs(int i){
	ok[i]=1;
	for(int j=1;j<=n;j++){
		if(ok[j]==0&&b[i][j]==1) dfs(j);
	}
}
void solve(){
	int dH=0;
	for(int i=0;i<e;i++){
		memset(ok,0,sizeof(ok));
		dfs(ds[i].d);
		if(ok[ds[i].c]==0){
			dH+=ds[i].m;ne++;k[ne].d=ds[i].d;k[ne].c=ds[i].c;
			b[ds[i].d][ds[i].c]=b[ds[i].c][ds[i].d]=1;
		}
	}
	if(ne==n-1){ cout<<dH<<endl;
	for(int i=1;i<=ne;i++) cout<<k[i].d<<" "<<k[i].c<<endl;
}
	else cout<<"no\n";	
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i][j]!=0){
					ds[e].d=i;ds[e].c=j;ds[e].m=a[i][j];e++;
				}
			}
		}
		for(int i=e;i>0;i--){
			for(int j=0;j<e;j++){
				if(ds[j].m>ds[j+1].m) swap(ds[j],ds[j+1]);
			}
		}
		solve();
	}
}
