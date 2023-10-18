#include <bits/stdc++.h>
using namespace std;
int main() {
    int tt; cin >> tt;
    while (tt--){
        int n; cin >> n;
        vector <int> v(n);
        for (auto &x : v) cin >> x;
        if (n % 2 == 0) {
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        }else {
            cout << 4 << "\n";
            cout << 2 << " " << n << "\n";
            cout << 2 << " " << n << "\n";
            cout << 1 << " " << 2 << "\n";
            cout << 1 << " " << 2 << "\n";
        }
    }
    return 0;
}