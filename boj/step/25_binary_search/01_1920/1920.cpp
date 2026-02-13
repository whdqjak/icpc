#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];

bool f(int x, int a, int b) {

    if (b - a < 0) return 0;

    int mid = (a + b) / 2;

    if (arr[mid] == x) return 1;
    if (arr[mid] < x) return f(x, mid+1, b);
    return f(x, a, mid-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N, 
        [](int a, int b) {
            return a < b;
        });

    int M, t;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> t;
        cout << f(t, 0, N-1) << '\n';
    }

    return 0;
}
