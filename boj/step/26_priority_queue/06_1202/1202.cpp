#include <bits/stdc++.h>
using namespace std;

struct dia{
    int m,v;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    vector<dia> d(N);
    for(int i = 0; i < N; i++)
        cin >> d[i].m >> d[i].v;

    vector<int> c(K);
    for(int i = 0; i < K; i++)
        cin >> c[i];

    sort(d.begin(), d.end(), [](const dia& a, const dia& b){
        return a.m < b.m;
    });
    sort(c.begin(), c.end());

    priority_queue<int> pq;
    long long ans = 0;

    int idx = 0;
    for(int i = 0; i < K; i++){
        while(idx < N && d[idx].m <= c[i]){
            pq.push(d[idx].v);
            idx++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    
    return 0;
}