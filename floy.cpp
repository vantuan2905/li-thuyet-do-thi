#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];int a[105][105];
void floy(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
}
main(){
	int t;
	t=1;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) a[i][j]=0;
				else a[i][j]=1e9;
			}
		}
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[x][y]=a[y][x]=z;
		}
		floy();
		int q;
		cin>>q;
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<a[x][y]<<endl;
		}
	}
}
