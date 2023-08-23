#include<bits/stdc++.h>
using namespace std;
int INF = 1e9+7 ;

bool isCycle(int src , int v , int e ,int edges[][3]){
    vector<int>dist(v,INF);
    dist[0] = 0 ;
    for(int i=0 ; i<v-1 ; i++){
        for(int j=0 ; j<e ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            //cout << u << " " << v << " " << w << endl;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w ;
            }
        }
    }

    for(int j=0 ; j<e ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            //cout << u << " " << v << " " << w << endl;

        if(dist[v] > dist[u] + w){
            return true ;
        }
    }

    return false ;


}

void bellmanFord(int src , int v , int e ,int edges[][3]){
    vector<int>dist(v,INF);
    dist[src] = 0 ;
    for(int i=0 ; i<v-1 ; i++){
        for(int j=0 ; j<e ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            //cout << u << " " << v << " " << w << endl;

            if(dist[u]!=INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w ;
            }
        }
    }
    cout << "Vertex distance from source :" << endl;
    for(int i=0 ; i<v ; i++){
        cout << i << "  ->  " << dist[i] << endl;
    }
    
}

int main(){
    int v , e  ;
    cin >> v >> e ;
    int edges[e][3];

    for(int i=0 ; i<e ; i++){
        int a , b , w ;
        cin >> a >> b >> w ;
        edges[i][0] = a ;
        edges[i][1] = b ;
        edges[i][2] = w ;
    }
    
    bellmanFord(0,v,e,edges);
    cout << isCycle(0,v,e,edges);
}