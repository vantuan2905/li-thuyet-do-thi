#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,e,k;vector<int> v[1005];int d[1005],ok[1005],mk[100][100];
struct gt{
	int di,deg;
};
void init(){
	for(int i=1;i<=n;i++) ok[i]=0;
}
vector<gt> vs;
void cntdeg(){
	for(int i=1;i<=n;i++){
		gt x;
		x.di=i;x.deg=v[i].size();vs.push_back(x);
	}
}
int cmp(gt a,gt b){
	return a.deg>b.deg;
}
main(){
	int t;
	cin>>t;
	while(t--){memset(d,0,sizeof(d));memset(v,0,sizeof(v));vs.clear();memset(mk,0,sizeof(mk));
		cin>>n>>e>>k;
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;mk[a][b]=mk[b][a]=1;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cntdeg();int cnt=0;
		sort(vs.begin(),vs.end(),cmp);
		for(int i=0;i<vs.size();i++){
			int ii=vs[i].di;
			if(d[ii]) continue;
			d[ii]=1;
			cnt++;
			for(int j=1;j<=n;j++){
				if(mk[ii][j]==0) d[j]=1;
			}
		}
	//	cout<<cnt<<endl;
		if(cnt<=k) cout<<"YES\n";
		else cout<<"NO\n";	
	}
}
