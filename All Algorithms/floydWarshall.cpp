#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7+10 ;
const int N = 200 ;
int dist[N][N];
int main(){

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(i==j) dist[i][j] = 0 ;
            else dist[i][j] = INF ;
        }
    }

    int v , e ;
    cin >> v >> e;
    for(int i=0 ; i<e ; i++){
        int a , b , wt ;
        cin >> a >> b >> wt ;
        dist[a][b] = wt ;
    }

    for(int k=1 ; k<=v ; k++){
        for(int i=1 ; i<=v ; i++){
            for(int j=1 ; j<=v ; j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=1 ; i<=v ; i++){
        for(int j=1 ; j<=v ; j++){
            if(dist[i][j]==INF) cout << "I" << " " ;
            else cout << dist[i][j] << " ";
        }cout << endl;
    }
}