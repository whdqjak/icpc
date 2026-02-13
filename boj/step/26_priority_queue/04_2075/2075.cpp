#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>> pq;
    
    int x;
    for (int i = 0; i < N * N; ++i) {
        cin >> x;

        pq.push(x);

        if (pq.size() > N)
            pq.pop();
    }

    cout << pq.top();
    
    return 0;
}