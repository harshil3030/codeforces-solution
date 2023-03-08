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
	cin >>tt;
	while(tt--){
		int n;
		cin>>n;
		int a[n];
		int cnt = 0;
		int cmt = 0;
		int cpt = 0; 
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			sum+=a[i];
		}

		for(int i = 0; i < n-1; i++){
			if(a[i]==a[i+1] && a[i]==-1){
				cnt++;
				break;
			}else if(a[i]!=a[i+1]){
				cmt++;
			}else{
				cpt++;
			}
		}

		if(cnt>0){
			cout<<sum+4<<endl;
		}else if(cmt>0){
			cout<<sum<<endl;
		}else{
			cout<<sum-4<<endl;
		}
	}

return 0;
}
