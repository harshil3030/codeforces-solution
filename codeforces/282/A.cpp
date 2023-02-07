#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
  char inp[10];
  int n,ans=0;
  scanf("%d",&n);
  while(n--)
    {
      scanf(" %s",inp);
      if(inp[1]=='+')
    ans++;
      else
    ans--;
    }
  printf("%d\n",ans);

return 0;
}
