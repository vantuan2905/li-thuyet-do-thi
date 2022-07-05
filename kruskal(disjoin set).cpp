#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct gt{
	int d,c,ts;
};
vector<gt> ds;
int par[1005];
void makeset(){
	for(int i=1;i<=n;i++) par[i]=i;
}
int find(int i){
	if(i==par[i]) return i;
	return par[i]=find(par[i]);
}
int cmp(gt a,gt b){
	return a.ts<b.ts;
}
void kruskal(){
	int h=0;
	for(int i=0;i<ds.size();i++){
		int a=find(ds[i].d),b=find(ds[i].c);
		if(a!=b){ h+=ds[i].ts;par[b]=a;}
	}
	cout<<h<<endl;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;ds.clear();
		for(int i=0;i<m;i++){
			gt g;
			cin>>g.d>>g.c>>g.ts;
			ds.push_back(g);
		}
		sort(ds.begin(),ds.begin()+m,cmp);
		makeset();
		kruskal();
	}
}
