#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
  int n;
  cin >> n;
  bool ok = true;
  vector<int> v(n);
  for(auto &x : v) cin >> x;
  for(int i = 0; i < n; i++) {
    if (v[i] != -1) ok = false;
  } 
  bool ok2 = true;
  for(int i = 0; i < n; i++) {
    if (v[i] == -1) ok2 = false;
  }
  if (ok2) {
      bool ok = true;
      for(int i = 0; i < n-1; i++) {
        ok &= ((v[i] == v[i+1]/2) || (v[i+1] == v[i]/2));
      }
      if (ok) {
          for(auto &x : v) {
            cout << x << " ";
          } cout << "\n";
     }else {
        cout << -1 << "\n";
     }
    return;
  }
  if (ok) {
    for(int i = 0; i < n; i++) {
        cout << ((i % 2 == 0) ? 1 : 2) << "  ";
    } cout << "\n";
    return;
  }

  int ini = -1;
  for(int i = 0; i < n; i++) {
    if (v[i] == -1) ini = i;
    else break;
  }

  int right = ini;
  int ele = v[ini + 1];
  while (right >= 0) {
    if (ele == 1) {
        v[right] = ((ini - right) % 2 == 0) ? 2 : 1;
        right--;
        continue;
    }
    v[right] =  ((ini - right) % 2 == 0) ? ele/2 : ele;
    right--;
  }

  int last = n;
  for(int i = n-1; i >= 0; i--) {
    if (v[i] == -1) last = i;
    else break;
  }
  int lastele = v[last - 1];
  int left = last;
  while (left <= n-1) {
    if (lastele == 1) {
        v[left] = ((left - last) % 2 == 0) ? 2 : 1;
        left++;
        continue;
    }
    v[left] = ((left - last) % 2 == 0) ? lastele/2 : lastele;
    left++;
  }

  int ffind = ini + 1; int ssind = -1;
  for (int i = ini + 2; i <= last-1; i++) {
    if (v[i] == -1) continue;
    if (v[i] != -1) {
        ssind = i;
    }

    int left = ffind + 1;
    int right = ssind - 1;
    while (left <= right) {
        if (v[left - 1] == 1 && v[right + 1] == 1) {
            v[right] = 2;
            right--;
            continue;
        }
        if (v[left-1] > v[right+1]) {
            v[left] = v[left-1]/2;
            left++;
        } else {
            v[right] = v[right+1]/2;
            right--;
        }
    }
    ffind = ssind;
  }

  ok = true;
  for(int i = 0; i < n-1; i++) {
    ok &= ((v[i] == v[i+1]/2) || (v[i+1] == v[i]/2));
  }

  if (!ok) {
    cout << -1 << endl;
    return;
  }

  for(auto &x : v) cout << x << " ";
  cout << endl;  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}