#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        unordered_map<long long, long long> cnt;
        unordered_map<long long, unordered_map<int, int>> pos;

        long long ans = 0;

        for (int i = 0; i + 4 < n; i++) {
            long long val = a[i] + a[i + 2] - a[i + 4];

            ans += cnt[val];

            if (pos[val].count(i - 2))
                ans--;

            if (pos[val].count(i - 4))
                ans--;

            cnt[val]++;
            pos[val][i]++;
        }

        cout << ans << endl;
    }

    return 0;
}