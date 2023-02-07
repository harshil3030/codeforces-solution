#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int a[5][5],sum=0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin>>a[i][j];
			if (a[i][j]==1)
			{
				if (i>2)
				{
					sum=sum+i-2;
				}else if (i<2)
				{
					sum=sum+2-i;
				}

				if (j>2)
				{
					sum+=j-2;
				}
				else if (j<2)
				{
					sum+=2-j;
				}
			}
		}
	}cout<<sum<<endl;

return 0;
}
