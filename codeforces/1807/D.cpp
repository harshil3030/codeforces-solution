#include<bits/stdc++.h>
using namespace std;
// #define for(i,k,n) for(int i = k; i < n; i++)
void Burst();
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		Burst();
	}
return 0;
}

  void Burst(){
	//write your solution from here
	int n,q;
	cin >> n >> q;
	long int tot=0;
	long int v[n],s[n];
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		tot+=v[i];
		s[i]=tot;
	}
	for(int i = 0; i < q; i++){
		long int a,b,c;
		cin >> a >> b >> c;
		long int x = c*(b-a+1)-(s[b-1]-s[a-1]+v[a-1]); 
		// cout<<x<<endl;
		(tot+x)%2?cout<<"YES\n":cout<<"NO\n";
	}
}