#include <bits/stdc++.h>
#define maxV 100
using namespace std;

int V;
int adj[maxV][maxV];
int c[maxV][maxV];

void floyd(){
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            c[i][j] = adj[i][j];
        }
    }

    for(int k = 0;k<V;++k){
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}