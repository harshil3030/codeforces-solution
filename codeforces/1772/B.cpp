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
		int a[2][2];
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				cin>>a[i][j];
			}
		}
		int min = a[0][0];
		int max = a[0][0];
		int temp1;
		int temp2;
		int temp3;
		int temp4;
		// if(a[0][0])
		for(int i  = 0; i < 2; i++){
			for(int j = 0; j < 2;j++){
				if(a[i][j]<=min){
					min = a[i][j];
					temp1 = i;
					temp2 = j;
				}

				if(a[i][j]>=max){
					max = a[i][j];
					temp3 = i;
					temp4 = j;
				}
			}
		}
		// cout<<temp1<<endl<<temp2<<endl<<temp3<<endl<<temp4;
		if(temp1!=temp3 && temp2!=temp4){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

return 0;
}
