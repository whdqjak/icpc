#include <bits/stdc++.h>
using namespace std;

int N, C;
int x[200000];

int absf(int a) {
    if (a < 0) return -a;
    return a;
}

bool cal(int n) {
    int cnt = 1;
    int last = x[0];

    for (int i = 1; i < N; i++) {
        if (x[i] - last >= n) {
            cnt++;
            last = x[i];
        }
    }

    return cnt >= C;
}


int f(int a, int b) {
    
    int r, l, mid, k;
    l = a, r = b;

    while (l <= r) {
        mid = (l + r)/2;
        if (cal(mid)) {
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; ++i) cin >> x[i];

    sort(x, x + N);
    cout << f(0, x[N - 1] - x[0]);

    return 0;
}
