#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

//write your code from here
    int t;
    cin >> t;
    char ch;
    for (int i = 0; i < t; ++i)
    {
        cin>>ch;
        if (ch=='c'||ch=='o'|| ch=='d'||ch=='e'||ch=='f'||
            ch=='r'||ch=='s')
        {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

return 0;
}
