#include <bits/stdc++.h>
using namespace std;
void design (vector<string> &v,int row, int col) {
    int flg = 0;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (v[i][j] == '.') {
                flg = 1;
                break;
            }
        }
    }
    if (flg) {
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (v[i][j] == '.') v[i][j] = '!';
            }
        }
    } else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (v[i][j] == '.') v[i][j] = '!';
            }
        }
    }
}
int main () {
    vector<string> v(9);
    for (int i = 0; i  < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char x; cin >> x;
            v[i].push_back(x);
        }
    }
    
    int n,m; cin >> n >> m;
    n--; m--;
    n %= 3; m %= 3; int x,y;
    design(v, n * 3, m * 3); 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << v[i][j];
            if (j % 3 == 2) cout << " ";    
        } cout << "\n";
        if (i % 3 == 2) cout << "\n";
    }
    return 0;
}