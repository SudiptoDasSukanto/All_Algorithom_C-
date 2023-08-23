#include<bits/stdc++.h>
using namespace std;
int INF = 1e9+7 ;

void shortestPath(int src, int v , vector<pair<int,int>> adj[]){
    vector<int>dist(v,INF);
    vector<bool>visited(v,false) ;
    typedef  pair<int , int > ipair ;
    priority_queue<ipair , vector<ipair> , greater<ipair>> pq ;

    pq.push(make_pair(0,src));  // first distance ,second node
    dist[src] =  0 ;
    while(!pq.empty()){
        int u =pq.top().second ;
        pq.pop();
        visited[u] = true ;
        for(auto nbr : adj[u]){
            int v = nbr.first ; // why it takes v ??
            int dis = nbr.second ;
            if(dist[v] > dist[u] + dis && visited[v] == false){ // without visited checking it work in negative cycle
                dist[v] = dist[u] +  dis ;
                pq.push(make_pair(dist[v] ,v)) ;
            }
        }
    }

    cout << " Vertex distance from source :" << endl;
    for(int i= 0 ; i<v ; i++){
        cout << i  << "  ->  " << dist[i] << endl;
    }
}

int main(){
    int v , e  ;
    cin >> v >> e ;
    vector<pair<int,int>> adj[v] ;
    for(int i=0 ; i<e ; i++){
        int a , b , w ;
        cin >> a >> b >> w ;
        adj[a].push_back(make_pair(b,w));
    }
    shortestPath(0,v,adj);
}