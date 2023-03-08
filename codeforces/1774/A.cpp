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
		// int a[n];
		string a;
		cin>>a;
		string s;
		int cnt = 0;
		// for(int i = 0; i < n; i++){
		// 	cin>> a[i];
		// }
		for(int i = 0; i < n; i++){
			if(a[i]=='1' && cnt%2==0){
				s+="+";
				cnt++;
			}else if(a[i]=='1' && cnt%2==1){
				s+="-";
				cnt++;
			}else{
				s+="+";
			}
		}

		s.erase(s.begin());
		cout<<s<<endl;
	}

return 0;
}
