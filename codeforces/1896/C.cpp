#include<bits/stdc++.h>
using namespace std;
int t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
// #define ff first
// #define ss second
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}

//sol.
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto &x : a) cin >> x; 
    vector<int> b(n); for (auto &x : b) cin >> x;
    // vector<int> temp = a;
    // vector<int> temp2 = b;
    // sort(temp.begin(), temp.end());
    // sort(temp2.begin(), temp2.end());
    // int mn = 0, mx = 0;
    // // int j = 0;
    // // for (int i = 0; i < n; i++) {
    // //     if (temp[i] > temp2[j]) {
    // //         mx++; j++;
    // //     }
    // // }
    // multiset<int> ms1,ms2;
    // for (int i = 0; i < n; i++) {
    //     ms1.insert(b[i]); ms2.insert(b[i]);
    // } 
    // multiset<int> extra1 = ms1;
    // multiset<int> extra2 = ms2;
    // for (int i = 0; i < n; i++) {
    //     auto it = ms1.lower_bound(temp[i]);
    //     if (it == ms1.begin()) {
    //         continue;
    //     }
    //     it--;
    //     ms1.erase(it);
    //     mx++;
    // }

    // for (int i = n-1; i>=0; i--) {
    //     auto it = ms2.lower_bound(temp[i]);
    //     if (it == ms2.end()) {
    //         continue;
    //     }
    //     ms2.erase(it);
    //     mn++;
    // }
    // mn = n-mn;
    // if (x > mx || x < mn) {
    //     cout << "NO\n";
    //     return;
    // }
    // map<int, vector<int>> mp;
    // int nottake = n-x;
    // // multiset<pair<pair<int,int>,int>> mset;
    // for (int i = n-1; i >= 0; i--) {
    //         auto it = extra1.lower_bound(temp[i]);
    //         if (nottake > 0) {
    //             if(it == extra1.end()) {
    //                 it = extra1.begin();
    //                 mp[temp[i]].push_back(*it); 
    //                 extra1.erase(it); 
    //             } else {
    //                 mp[temp[i]].push_back(*it); 
    //                 extra1.erase(it);
    //                 nottake--; 
    //             }
    //         }else {
    //             it = extra1.begin();
    //             mp[temp[i]].push_back(*it); 
    //             extra1.erase(it); 
    //         }
    //         // if (it == extra1.begin()) {
    //         //     it = extra1.end(); it--;
    //         //     mp[temp[i]].push_back(*it); 
    //         //     extra1.erase(it); 
    //         // }
    //         // else if(x > 0){
    //         //     // it = extra1.end(); 
    //         //     it--;
    //         //     mp[temp[i]].push_back(*it);
    //         //     extra1.erase(it);
    //         //     x--;
    //         // } else {
    //         //     it = extra1.end(); it--;
    //         //     mp[temp[i]].push_back(*it); 
    //         //     extra1.erase(it); 
    //         // }
    //         // // else {
    //         // //     it--;
    //         // //     mp[temp[i]].push_back(*it);
    //         // //     extra1.erase(it);
    //         // }
    // }
    // cout << "YES\n";
    // // int j = n-1; int k = 0;
    // // for (int i = 0; i < n; i++) {
    // //     if (x > 0) {
    // //         if (temp[i] > temp2[k]) {
    // //             mp[temp[i]].push_back(temp2[k]);
    // //             x--; k++;
    // //         }else {
    // //             mp[temp[i]].push_back(temp2[j]);
    // //             j--;
    // //         }   
    // //     }else {
    // //             mp[temp[i]].push_back(temp2[j]);
    // //             j--;
    // //     }
    // // }
    // // for (auto x : mp) {     
    // //     cout << "x : " << x.first << "\n";
    // //     for (auto &y : x.second) {
    // //         cout << y << " ";
    // //     } cout << "\n";
    // // }
    // map<int, int> getind;
    // for (int i = 0; i < n; i++) {
    //     cout << mp[a[i]][getind[a[i]]] << " ";
    //     getind[a[i]]++;
    // } cout << "\n";

   vector<int> temp = a;
   sort(temp.begin(), temp.end());
   vector<int> temp2 = b;
   sort(temp2.begin(), temp2.end());
   int val = x;
   vector<int> final(n);
   for (int i = 0; i < x; i++) {
        final[i] = temp2[n-x+i];
   }
   val =n-x;
   for (int i = n-x; i < n; i++) {
        final[i] = temp2[i-(n-x)];
   }
   for (int i = 0; i < n-x; i++) {
        final[i] = temp2[x+i];
   }
   map<int,vector<int>> mp;
   map<int, int> getind;

   for (int i = 0; i < n; i++) {
        mp[temp[i]].push_back(final[i]);
   }

   // cout << "here: " ;
   // for (int i = 0; i < n; i++) {
   //  cout << "temp : " << temp[i] << " ";
   //  cout << final[i] << " " << "\n";
   // }


   int count = 0;
   for (int i = 0; i < n; i++) {
        if (temp[i] > final[i]) count++;
   }
   if (count == x) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << mp[a[i]][getind[a[i]]] << " ";
            getind[a[i]]++;
        } cout << "\n";
   } else cout << "NO\n";
 }

    
    



