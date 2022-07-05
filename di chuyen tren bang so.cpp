#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int x,y,c;
};
int xx[20]={-1,0,0,1};
int yy[20]={0,-1,1,0};
struct cmp{
	bool operator()(gt a,gt b){
		return a.c>b.c;
	}
};
main(){
	int t;
	cin>>t;
	while(t--){
		int a[505][502],n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}int ok[505][505]={0};ok[0][0]=1;
		priority_queue<gt,vector<gt>,cmp> q;q.push({0,0,a[0][0]});
		while(q.size()){
			gt s=q.top();q.pop();
			if(s.x==n-1&&s.y==m-1){
				cout<<s.c<<endl;break;
			}
			for(int i=0;i<4;i++){
				int ii=s.x+xx[i],jj=s.y+yy[i];
				if(ok[ii][jj]==0&&ii>=0&&jj>=0&&ii<n&&jj<m){ok[ii][jj]=1;
					q.push({ii,jj,s.c+a[ii][jj]});
				}
			}
		}
	}
}
