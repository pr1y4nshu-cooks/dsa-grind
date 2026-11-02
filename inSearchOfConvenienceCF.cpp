#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int x0, y0, R;
        cin >> x0 >> y0 >> R;

        for (int dx = -R; dx <= R; dx++){
            for (int dy = -R; dy <= R; dy++){
                if (dx * dx + dy * dy == R * R){
                    cout << x0 + dx << ' ' << y0 + dy << endl;
                    goto found;
                }
            }
        }
        found:;
    }
    return 0;
}