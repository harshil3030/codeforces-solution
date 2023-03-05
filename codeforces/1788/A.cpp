// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// #endif

// //write your code from here
// 	int tt;
// 	cin>>tt;
// 	while(tt--){
// 		int n;
// 		cin>>n;
// 		int a[n];
// 		for (int i = 0; i < n; ++i)
// 		{
// 			cin>>a[i];
// 		}

// 		int s = 0;
// 		int e = n-1;
// 		int sum1 = 1;
// 		int sum2 = 1;
// 		while(e-s>0){
// 			int mid = (s+e)/2;
// 			if(sum1*a[s]>a[e]*sum2){
// 				// sum1*=a[s];
// 				sum2*=a[e];
// 				e--;
// 			}else if(sum1*a[s]<a[e]*sum2){
// 				sum1*=a[s];
// 				s++;
// 			}else if(sum1*a[s]==a[e]*sum2 && (e-s==2||e-s==1))
// 			{	cout<<sum1<<" "<<sum2;
// 				cout<<s<<endl;
// 				goto exit;
// 			}else{
// 				sum1*=a[s];
// 				sum2*=a[e];
// 				s++;
// 				e--;
// 			}
// 		}
// 		cout<<sum1<<" "<<sum2;
// 		cout<<-1<<endl;
// 		exit:;
// 	}

// return 0;
// }
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
		int n;cin>>n;
		int a[n];
		int cnt = 0;
		for(int i = 0; i < n; i++) cin>>a[i];

		for(int i = 0; i<n; i++){
			if(a[i]==2) cnt++;
		}
		int cmt = cnt/2;
		if(cnt==0) cout<<1<<endl;
		else if(cnt%2) cout<<-1<<endl;
		else{
			int i = 0;
			// if(cmt==0) cout<<1<<endl; goto exit;
			while(cmt!=0){
				if(a[i]==2) {
					cmt--;
				}i++;
			}
			cout<<i<<endl;
		}
		// exit:;

	}

return 0;
}
