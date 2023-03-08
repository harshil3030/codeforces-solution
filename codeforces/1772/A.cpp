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
		string s;
		int sum = 0;
		cin>>s;
		switch(s[0]){
		case '0':sum+=0;break;
		case '1':sum+=1;break;
		case '2':sum+=2;break;
		case '3':sum+=3;break;
		case '4':sum+=4;break;
		case '5':sum+=5;break;
		case '6':sum+=6;break;
		case '7':sum+=7;break;
		case '8':sum+=8;break;
		case '9':sum+=9;break;
		}
		// cout<<sum;

		switch(s[2]){
		case '0':sum+=0;break;
		case '1':sum+=1;break;
		case '2':sum+=2;break;
		case '3':sum+=3;break;
		case '4':sum+=4;break;
		case '5':sum+=5;break;
		case '6':sum+=6;break;
		case '7':sum+=7;break;
		case '8':sum+=8;break;
		case '9':sum+=9;break;
		}

		cout<<sum<<endl;
	}

return 0;
}
