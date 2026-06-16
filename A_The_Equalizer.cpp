#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    if (total%2 != 0) {
        cout << "YES" << endl;
    } else {
        int MJ = n*k;
        if (MJ%2 == 0) {
            cout << "YES"<< endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}