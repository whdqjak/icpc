#include <bits/stdc++.h>
using namespace std;

int N, K;

long long f(int low, int high) {

	while (low < high) {
		int mid = (low + high) / 2, cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}

		if (cnt < K) low = mid + 1;
		else high = mid;
	}

	return high;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

	cout << f(1, (int)1e9);

    return 0;
}
