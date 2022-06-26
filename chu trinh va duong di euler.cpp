#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k,a[200][200];
void euler(int u){
	stack<int> st,eu;
	st.push(u);
	while(st.size()){
		int x=st.top();int kt=0;
		for(int i=1;i<=n;i++){
			if(a[x][i]==1){
				a[x][i]=a[i][x]=0;
				st.push(i);kt=1;break;
			}
		}
		if(kt==0){
			st.pop();eu.push(x);
		}
	}
	while(eu.size()){
		cout<<eu.top()<<" ";eu.pop();
	}
	cout<<endl;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
		euler(k);
	}
}
