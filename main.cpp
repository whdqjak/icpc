#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;

    while(T--){
        string odr;
        int n;
        string list;
        deque<int> dq;

        cin>>odr;
        cin>>n;
        cin>>list;

        int rn = 0;
        bool f = 0; //rn이 숫자로 제작 됐는지 안됐는지
        for(int i=1;i<list.size();++i){
            if('0'<=list[i] && list[i]<='9'){
                f=1;

                rn*=10;
                rn+=list[i]-'0';
            }
            else if(f){
                dq.push_back(rn);
                rn=0;
                f=0;
            }
        }

        int r = 1;  // 1은 정방향 -1은 역방향
        bool er=0;  //error
        for(int i=0;i<odr.size();++i){
            if(odr[i]=='R') r*=-1;
            else{   //D
                if(dq.empty()){
                    er=1;
                    break;
                }
                else if(r==1) dq.pop_front();
                else dq.pop_back();
            }
        }

        //출력부분
        if(er) cout<<"error\n";
        else{
            cout<<'[';
            if(r==1 && !dq.empty()){
                cout<<dq.front();
                dq.pop_front();
                while(!dq.empty()){
                    cout<<','<<dq.front();
                    dq.pop_front();
                }
            }
            else if(r==-1 && !dq.empty()){
                cout<<dq.back();
                dq.pop_back();
                while(!dq.empty()){
                    cout<<','<<dq.back();
                    dq.pop_back();
                }
            }
            cout<<"]\n";
        }
    }
    
    return 0;
}