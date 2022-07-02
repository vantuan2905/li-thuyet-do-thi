#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ok[105][105];vector<int> v[1005];int a[200][200],cuu[105][105];int c;
int xx[10]={-1,0,0,1};
int yy[10]={0,-1,1,0};
struct gt{
	int u=1,d=1,l=1,r=1;
};
gt ds[105][105];
void dfs(int i,int j){
	if(i<=0||i>n||j<=0||j>n) return;
	ok[i][j]=1;
	if(cuu[i][j]==1){//cout<<i<<" "<<j<<"-";
		cuu[i][j]=0;c++;
	}
	if(ds[i][j].l==1&&ok[i][j-1]==0) dfs(i,j-1);
	if(ds[i][j].r==1&&ok[i][j+1]==0) dfs(i,j+1);
	if(ds[i][j].u==1&&ok[i-1][j]==0) dfs(i-1,j);
	if(ds[i][j].d==1&&ok[i+1][j]==0) dfs(i+1,j);
}
main(){
	int tt;
	tt=1;
	while(tt--){
		cin>>n>>k>>m;
		for(int i=0;i<m;i++){
			int x,y,z,t;
			cin>>x>>y>>z>>t;
			if(x==z){
				if(y>t) swap(t,y);
				ds[x][y].r=0;ds[x][t].l=0;
			}
			if(t==y){
				if(x>z) swap(x,z);
				ds[x][y].d=0;ds[z][t].u=0;
			}
		}
		int q;
		q=k;
		for(int i=0;i<q;i++){
			int x,y;
			cin>>x>>y;
			cuu[x][y]=1;
		}int cnt=0;//cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cuu[i][j]==1){ c=0;
					
					dfs(i,j);//cout<<i<<" "<<j<<endl;
					cnt+=(k-c)*c;
					k-=c;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
