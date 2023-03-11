#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int tt;
	cin >> tt;
	while(tt--){
		int n,k;
		cin >> n >> k;
		vector <int> a(n);
		vector <int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cin >> b[i];
		}
		int cnt = 0;
		// for(int i = 0; i < n; i++){
		// 	if(a[i]==k && b[i]==k){
		// 		cout<<"YES\n";
		// 		goto exit;
		// 	}
		// }
		// cout<<"NO\n";
		for(int i  = 0; i < n; i++){
			if(a[i]==k){
				cnt++;
				break;
			}
		}
		for(int i = 0; i < n; i++){
			if(b[i]==k){
				cnt++;
				break;
			}
		}
		// exit:;
		if(cnt==2) cout<<"YES\n";
		else cout<<"NO\n";
	}

return 0;
}
