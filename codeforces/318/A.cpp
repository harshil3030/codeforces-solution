#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

//write your code from here
    long long int a,b;
    cin >> a>> b;
    if(a%2){
        if(b>a/2+1){
            cout<<(2*(b-a/2-1))<<endl;
        }else if(b<=a/2+1){
            cout<<(b*2)-1;
        }
    }else{
        if(b>a/2){
            cout<<(2*(b-a/2))<<endl;
        }else{
            cout<<b*2-1<<endl;
        }
    }

return 0;
}
