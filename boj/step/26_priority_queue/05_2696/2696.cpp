#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;

    cin>>T;

    int M, e;
    while(T--){
        
        priority_queue<int> lq;
        priority_queue<int, vector<int>, greater<int>> rq;

        cin>>M;
        cout<< (M/2)+(M&1) << '\n';
        for(int i=1;i<=M;++i){
            cin>>e;
            if(lq.size()==rq.size())
                lq.push(e);
            else
                rq.push(e);

            if((i>1)&&(lq.top()>rq.top())){
                rq.push(lq.top());
                lq.pop();

                lq.push(rq.top());
                rq.pop();
            }
            
            if(i&1)
                cout<<lq.top()<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}