#include <bits/stdc++.h>
using namespace std;

int N, K;
long long arr[10000];

long long cal(int l) {

    long long cnt = 0;
    for (int i = 0; i < N; ++i) cnt += arr[i] / l;
    return cnt;
}

long long f() {

    long long l = 1, r = 0;
    for (int i = 0; i < N; ++i)
        r = max(r, arr[i]);

    long long ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (cal(mid) >= K) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    cin >> arr[0];
    for (int i = 1; i < N; ++i)
        cin >> arr[i];
    cout << f();

    return 0;
}
