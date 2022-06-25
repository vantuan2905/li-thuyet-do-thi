#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct gt{
	int d,c;
};
main(){
	int t;
	t=1;
	while(t--){
		vector<gt> v[1005];
		int n;
		cin>>n;cin.ignore();
		for(int i=1;i<=n;i++){
			string s;
			getline(cin,s);
			stringstream ss(s);int x=0;
			//cout<<i<<":\n";
			while(ss>>x){//cout<<i<<"--"<<x<<endl;
				if(i<x) cout<<i<<" "<<x<<endl;
			}
		}
	}
}
