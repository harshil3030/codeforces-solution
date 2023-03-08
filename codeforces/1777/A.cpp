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
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		int cnt = 0;


		for(int i = 0; i < n-1; i++){
			if((a[i]%2 && a[i+1]%2) || (a[i]%2==0 && a[i+1]%2==0)){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}

return 0;
}
