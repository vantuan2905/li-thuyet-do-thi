#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	t=1;
	while(t--){
		int n,m;
		cin>>n;int x[1005][100]={0};cin.ignore();
		for(int i=1;i<=n;i++){
			string s;
			getline(cin,s);
			stringstream ss(s);
			int z=0;
			while(ss>>z) x[z][i]=x[i][z]=1;
		}
		for(int i=1;i<=n;i++){ for(int j=1;j<=n;j++) cout<<x[i][j]<<" ";cout<<endl;}
		
	}
}
