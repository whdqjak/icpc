#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500001];

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

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int m;
    cin >> m;

    int t;
    for(int i=0;i<m;++i){
        cin >> t;
        cout << upper_bound(arr, arr + N, t) - lower_bound(arr, arr + N, t) << '\n';
    }

    return 0;
}
