#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab {
    ll a, b, c, sum, cost;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<Lab> v(n);
        ll lo = LLONG_MAX;

        for (auto &[a, b, c, sum, cost] : v) {
            cin >> a >> b >> c;
            sum = a + b + c;
            lo = min(lo, sum);

            if (a == b && b == c) {
                cost = -1;
            } else if (a <= b && b <= c) {
                cost = 2 * min(b - a, c - b) + 3;
            } else {
                cost = 1;
            }
        }

        auto possible = [&](ll target) {
            ll need = 0;

            for (auto &x : v) {
                if (x.sum >= target)
                    continue;

                if (x.cost == -1)
                    return false;

                ll deficit = target - x.sum;
                ll cur = deficit + x.cost - 1;

                need += cur;

                if (need > k)
                    return false;
            }

            return need <= k;
        };

        ll l = lo, r = lo + k + 1;

        while (l + 1 < r) {
            ll mid = l + (r - l) / 2;

            if (possible(mid))
                l = mid;
            else
                r = mid;
        }

        cout << l << endl;
    }

    return 0;
}