#include <bits/stdc++.h>
#define big 2000000001
using namespace std;

int N, M;
int arr[1000000];

long long cal(int h) {
    long long cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > h)
            cnt += arr[i] - h;

        if (cnt > big) return big;
    }
    return cnt;
}

int f(int a, int b) {

    int l = a, r = b;
    int ans = 0;

    int mid;
    long long wood;

    while (l <= r) {
        mid = (l + r) / 2;
        wood = cal(mid);

        if (wood >= M) {
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

    
    cin >> N >> M;

    cin >> arr[0];
    int max = arr[0];
    for (int i = 1; i < N; ++i) {
        cin >> arr[i];
        if (max < arr[i]) max = arr[i];
    }
    cout << f(0, max);

    return 0;
}
