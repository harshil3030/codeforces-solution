#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int k,w;
	long long int n;
	cin>>k>>n>>w;
	int sum = 0;
	for (int i = 1; i <= w; ++i)
	{
		sum+=k*i;
	}
	if (sum-n<0)
	{
		cout<<0;
	}else
	cout<<sum-n<<endl;
return 0;
}
