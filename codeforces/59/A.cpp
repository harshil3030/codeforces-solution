#include<bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	char s[100];
	cin>>s;
	int count=0;
	int countcap=0;
	int i=0;
	while(s[i]!='\0'){
		if (s[i]>=65 && s[i]<=90)
		{
			countcap++;
		}else{
			count++;
		}
		i++;
	}
	i=0;
	while(s[i]!='\0')
	{
		if (countcap>count)
		{
			if (s[i]>=65 && s[i]<=90)
			{
				cout<<s[i];
			}else{
				s[i]=s[i]-32;
				cout<<s[i];
			}
		}else{
			if (s[i]>=65 && s[i]<=90)
			{
				s[i]=s[i]+32;
				cout<<s[i];
			}else{
				cout<<s[i];
			}
		}
		i++;
	}
	return 0;
}

