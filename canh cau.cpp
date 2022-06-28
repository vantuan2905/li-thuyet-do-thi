#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int> v[1005];int ok[1005];int tplt;
void dfs(int u){
	ok[u]=1;//cout<<u<<" ";
	for(int i=0;i<v[u].size();i++) if(ok[v[u][i]]==0) dfs(v[u][i]);
}
int dem(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ok[i]==0){
			cnt++;dfs(i);//cout<<endl;
		}
	}
	memset(ok,0,sizeof(ok));
	return cnt;
}
void cau(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			int s=v[i][j],ss,vt;
			if(s<i) continue;v[i].erase(v[i].begin()+j,v[i].begin()+j+1);
			for(int x=0;x<v[s].size();x++){
				if(v[s][x]==i){vt=x;
					ss=v[s][x];v[s].erase(v[s].begin()+x,v[s].begin()+x+1);break;
				}
			}
			int cnt=dem();
			//cout<<cnt<<" "<<tplt<<"++++"<<endl;
			if(cnt>tplt) cout<<i<<" "<<s<<" ";
			v[i].insert(v[i].begin()+j,s);
			v[s].insert(v[s].begin()+vt,i);//cout<<cnt<<" ";
		}
	}
	cout<<endl;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;memset(v,0,sizeof(v));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		tplt=dem();
		cau();
	}
}
