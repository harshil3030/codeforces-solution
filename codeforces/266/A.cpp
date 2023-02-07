#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	char s[50];
	int n;
	cin >> n;
	cin >> s;
	int count = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if(s[i]==s[i+1]){
			count++;
		}
	}

cout<<count<<endl;
return 0;
}
