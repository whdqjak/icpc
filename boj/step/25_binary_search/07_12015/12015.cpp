#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> dp;

    for (int i = 0; i < N; ++i) {
        int x = A[i];

        auto it = lower_bound(dp.begin(), dp.end(), x);

        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }

    cout << dp.size() << '\n';
    return 0;
}

