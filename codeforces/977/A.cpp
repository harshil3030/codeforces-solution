#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int k;
	long long int n;
	cin>>n>>k;
	for (int i = 0; i < k; ++i)
	{
		if ((n%10)!=0)
		{
			n=n-1;
		}else{
			n=n/10;
		}
	}cout<<n<<endl;

return 0;
}
