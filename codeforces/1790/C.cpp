#include<bits/stdc++.h>
using namespace std;


//              defines
#define f(i,k,n) for(int i = k; i < n; i++)
#define ll  long long
#define l1(a)  ll a; cin >> a;
#define l2(a,b)  ll a,b; cin >> a >> b;
#define l3(a,b,c)  ll a,b,c; cin >> a >> b >> c;
#define l4(a,b,c,d)  ll a,b,c,d; cin >> a >> b >> c >> d;
#define l5(a,b,c,d,e)  ll a,b,c,d,e; cin >> a >> b >> c >> d >> e;


//user-defined function
ll search(ll[],int,int,int);
  //array,target,start,end
void Burst();

//taking number of testcases
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
  ll tt;
  cin >> tt;
  while(tt--){
    Burst();
  }
return 0;
}

ll search(ll a[],int t,int s,int e){
  if(s > e) {
        return -1; //element not found
    }
    int m = s + (e - s) / 2;
    if(a[m] == t) {
        return m; //element found at index m
    }
    else if(a[m] > t) {
        return search(a, t, s, m-1); //search in left subarray
    }
    else {
        return search(a, t, m+1, e); //search in right subarray
    }
}

  void Burst(){
  //write your solution from here
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    map<int, int> mp;
    f(i,0,n){
      f(j,0,n-1){
        int x; cin >> x;
        v[i].push_back(x);
        if(i == 0){
          mp[x]++;
        }
      }
    }

    vector<int> b;
    f(i,0,n-1){
      b.push_back(v[0][i]);
    }
    set <int> s;
    int in;
    // sort(v[0].begin(),v[0].end());

    f(i,0,n){
      if(mp[i+1] == 0){
        in = i+1;
        break;
      }
    }
    
    int j = 0;
    for(int i = 1; i < n; i++){
        while(v[i][j] != in){
        s.insert(v[i][j++]);
      } j = 0;
    }

    b.insert(b.begin()+s.size(),in);
    for(int i = 0; i < b.size(); i++){
      cout << b[i] <<" ";
    }cout << "\n";
}

  
  
  