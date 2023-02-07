#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int n;
	int a[3];
	cin >> n;
	int count = 0;
	int count1 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> a[j];
			if (a[j]==1)
			{
				count++;
			}
			
		} if (count>=2)
			{
				count1++;
			}
		count=0;
	}
	cout<<count1<<endl;
return 0;
}
