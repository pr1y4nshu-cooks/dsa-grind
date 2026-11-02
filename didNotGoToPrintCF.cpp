#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        stack<int> st;
        vector<bool> printed(n + 1, false);

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {

                st.push(i);
            }
            else if (s[i - 1] == '2') {
                if (!st.empty()) {
                    // print top document 
                    printed[st.top()] = true;
                    st.pop();
                } 
                else {
                    //memory empty
                    printed[i] = true;
                }
            }
            else { 
                // quick print document i
                printed[i] = true;
            }
        }

        vector<int> notPrinted;

        for (int i = 1; i <= n; i++) {
            if (!printed[i]) {
                notPrinted.push_back(i);
            }
        }

        cout << notPrinted.size() << '\n';

        for (int x : notPrinted) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}