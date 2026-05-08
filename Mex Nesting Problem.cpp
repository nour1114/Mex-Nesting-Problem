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

        vector<int> a(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        vector<int> first(n, -1), last(n, -1);

        for (int i = 0; i < 2 * n; i++) {
            if (first[a[i]] == -1)
                first[a[i]] = i;
            else
                last[a[i]] = i;
        }

        int mex = 0;

        while (mex < n) {
            if (last[mex] - first[mex] <= 1)
                break;

            bool ok = true;

            for (int i = 0; i < mex; i++) {
                if (!(first[i] < first[mex] && last[i] > last[mex])) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                break;

            mex++;
        }

        cout << mex << '\n';
    }

    return 0;
}