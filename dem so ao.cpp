#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];char ds[100][100];
int x[20]={-1,-1,-1,0,0,1,1,1};
int y[20]={-1,0,1,-1,1,-1,0,1};
void dfs(int i,int j){
	ds[i][j]='.';
	for(int k=0;k<8;k++){
		int xx=i+x[k],yy=j+y[k];
		if(xx>=1&&xx<=n&&yy>=0&&yy<=m&&ds[xx][yy]=='W'){
			dfs(xx,yy);
		}
	}
}
main(){
	int t=1;
	while(t--){
		cin>>n>>m;int cnt=0;cin.ignore();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>ds[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ds[i][j]=='W'){
					dfs(i,j);cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
