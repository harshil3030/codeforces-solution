// // // // #include<bits/stdc++.h>
// // // // using namespace std;
// // // // int powr(int a,int b){
// // // // 	for(int i = 0; i < b; i++){
// // // // 		a*=a;
// // // // 	}
// // // // }
// // // // int main()
// // // // {
// // // // #ifndef ONLINE_JUDGE
// // // // 	freopen("input.txt","r",stdin);
// // // // 	freopen("output.txt","w",stdout);
// // // // #endif

// // // // //write your code from here
// // // // 	int tt;
// // // // 	cin>>tt;
// // // // 	while(tt--){
// // // // 		long long int n; 
// // // // 		cin>>n;
// // // // 		// cout<<n;
// // // // 		long long int s = 1;
// // // // 		long long int e = 1;
// // // // 		while(1){
// // // // 			if((pow(s,e)*e)+(pow(e,s)*s)<n){
// // // // 				if(s>e){
// // // // 					e++;
// // // // 				}else{
// // // // 					s++;
// // // // 				}
// // // // 			}else if((pow(s,e)*e)+(pow(e,s)*s)==n){
// // // // 				cout<<s<<" "<<e<<endl;
// // // // 				break;
// // // // 			}else if((pow(s,e)*e)+(pow(e,s)*s)>n){
// // // // 				// cout<<(pow(s,e)*e)+(pow(e,s)*s)<<endl;
// // // // 				cout<<s<<" "<<e<<endl;
// // // // 				cout<<-1<<endl;
// // // // 				break;
// // // // 			}

// // // // 		}


// // // // 	}

// // // // return 0;
// // // // }
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // int main()
// // // {
// // // #ifndef ONLINE_JUDGE
// // // 	freopen("input.txt","r",stdin);
// // // 	freopen("output.txt","w",stdout);
// // // #endif

// // // //write your code from here
// // // 	// int a[5] = {2,2,1,3,4};
// // // 	vector <int> a;
// // // 	for (int i = 0; i < 5; ++i)
// // // 	{
// // // 		int x; cin>>x;
// // // 		a.push_back(x);
// // // 	}
// // // 	sort(a.rbegin(),a.rend());
// // // 	for (int i = 0; i < 5; ++i)
// // // 	{
// // // 		cout<<a[i]<<" ";
// // // 	}

// // // return 0;
// // // }
// // #include<bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// // #ifndef ONLINE_JUDGE
// // 	freopen("input.txt","r",stdin);
// // 	freopen("output.txt","w",stdout);
// // #endif


// // //write your code from here
// // 	string s;
// // 	int n = 6;
// // 	s=48+n;
// // 	cout<<s<<endl;
// // return 0;
// // }

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
// 		vector <int> a;
// 		int cnt = 0;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			// cin>>a[i];
// 			int x;
// 			cin>>x;
// 			a.push_back(x);
// 		}
// 		sort(a.rbegin(),a.rend());
// 		for(int i = 0; i < n-1; i++){
// 			if(a[i]!=a[i+1]){
// 				break;
// 			}cnt++;
// 		}
// 		if(cnt==0){
// 			cout<<"YES"<<endl;
// 			for(int i = 0; i < n; i++){
// 				cout<<a[i]<<" ";
// 			}cout<<endl;
// 		}else{
// 			// int temp = a[1];
// 			// a[1] = a[n-1];
// 			// a[n-1] = temp;
// 			int j = n-1;
// 			while(a[0]==a[1] && j>1){
// 				int temp  = a[1];
// 				a[1] = a[j];
// 				a[j] = temp;
// 				j--;
// 			}

// 			if(a[0]!=a[1]){
// 				cout<<"YES"<<endl;
// 				for (int i = 0; i < n; ++i)
// 				{
// 					cout<<a[i]<<" ";
// 				}cout<<endl;
// 			}else{
// 				cout<<"NO"<<endl;
// 			}

// 		}
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
		int n;
		cin>>n;
		int cnt = 0;
		vector <int> a;
		vector <int> ans;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		if(n==3){
			for (int i = 0; i < 3; ++i)
			{
				if(a[i]%2){
					cnt++;
				}
			}

			if(cnt==1 || cnt==3){
				cout<<"YES\n";
				for (int i = 0; i < 3; ++i)
				{
					cout<<i+1<<" ";
				}cout<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}

		else{
		for(int i = 0; i < n; i++){
			if(a[i]%2){
				cnt++;
				// ans.push_back(i+1);
			}
		}
			if(cnt==0){
				cout<<"NO"<<endl;
			}else if(cnt!=0){
				cout<<"YES\n";
				int cmt = 0;
				int cpt = 0;
				if(cnt>=3){
				for(int i = 0; i < n; i++){
					// sort(a.begin(),a.end(),comp)
					if(a[i]%2 && cmt<3){
						cout<<i+1<<" ";
						cmt++;
					}
				}cout<<endl;
			  }else if(cnt==2){
			  	for (int i = 0; i < n; ++i)
			  	{
			  		if(a[i]%2 && cmt<1){
			  			cout<<i+1<<" ";

			  			cmt++;
			  		}

			  		if(a[i]%2==0 && cpt<2){
			  			cout<<i+1<<" ";
			  			cpt++;
			  		}
			  		// }cout<<endl;
			  	}cout<<endl;
			  }else if(cnt == 1){
			  	for(int i = 0; i < n; i++){
			  		if(a[i]%2 && cmt<1){
			  		cout<<i+1<<" ";
			  		cmt++;
			  		}
			  		if(a[i]%2==0 && cpt<2){
			  			cout<<i+1<<" ";
			  			cpt++;
			  		}
			  }cout<<endl;
		 }
			}
		}
	}


return 0;
}
