#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 500005;
const int MOD = 1e9 + 7;

int spf[MAXA];
long long primeCount[MAXA];

void sieve() {
    for (int i = 1; i < MAXA; i++) {
        spf[i] = i;
    }
    for (int i = 2; i*i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    vector<int> usedPrimes;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int temp = a[i];

        while (temp > 1) {
            int p = spf[temp];
            int count = 0;

            while (temp%p == 0) {
                count++;
                temp /= p;
            }

            if (primeCount[p] == 0) {
                usedPrimes.push_back(p);
            }
            primeCount[p] += count;
        }
    }

    long long ans = 1;

    for (int p : usedPrimes) {
        ans = (ans * (primeCount[p] + 1)) % MOD;
        primeCount[p] = 0;
    }

    cout << ans << "\n";
}

int main() {

    sieve();
    
    int n;
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}