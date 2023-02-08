#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	long long int n;
	cin>>n;
	int count = 0;
	int countn = 0;
	int rem=0;
	long long int ori = n;
	while(n>0){
		rem = n%10;
		
		if (rem == 4 || rem ==7)
		{
			count++;
		}

		countn++;
		n=n/10;
	}
	

	if (ori>46 && (count==4||count==7)){
		cout<<"YES";
	}else {
		cout<<"NO";
	}
	

return 0;
}
