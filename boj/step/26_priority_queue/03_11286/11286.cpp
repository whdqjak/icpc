#include <bits/stdc++.h>
using namespace std;

typedef struct cmp{
    bool operator()(int a, int b) const{
        if(abs(a)==abs(b)) return a>b;
        return abs(a)>abs(b);
    }
}cmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, cmp> pq;
    
    int X;
    for(int i=0;i<N;++i){
        cin>>X;
        if(X!=0){
            pq.push(X);
        }
        else{
            if(pq.empty()) cout<<0<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();    
            }
        }
    }

    
    return 0;
}