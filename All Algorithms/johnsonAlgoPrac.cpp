#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7+10 ;

class Edges
{
    public:
    int u , v , wt ;
    Edges(int u, int v , int wt){
        this->u = u ;
        this->v = v ;
        this->wt = wt ;
    }
};

void bellmanFord(int start,int V, vector<Edges>& edges,vector<int>& h){
    h[start] = 0 ;
    
    for(int i=0 ; i<V-1 ; i++){
        for(auto& edge : edges){
            int u = edge.u;
            int v = edge.v ;
            int wt = edge.wt;
            //cout << u << " " << v << " " << wt << endl;

            if(h[u]!=INF && h[v]> h[u]+wt){
                h[v] = h[u] + wt ;
            }
        }
    }

    // for(int i=1 ; i<V ; i++){
    //     cout << h[i] <<" "; 
    // }cout << endl;

}

void dijkstra(int start ,int V, vector<vector<Edges>> &graph , vector<int> & dist){
    dist[start] = 0 ;
    vector<bool>visited(V+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int uu = pq.top().second;
        pq.pop();
        
        visited[uu] = false ;

        for(auto& edge : graph[uu]){
            int u = edge.u;
            int v = edge.v ;
            int wt = edge.wt;
            //cout << u << " " << v << " " << wt << endl;

            if(visited[v]==false && dist[u]!=INF && dist[v]>dist[u]+wt){
                dist[v] = dist[u]+wt ;
                //cout << v << " " << dist[v] << endl;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

void johnsonAlgo(int V , int E, vector<vector<Edges>> &graph,vector<vector<int>> &shortestpath){

    int newVertex = 0 ;
    for(int i=1 ; i<V+1 ; i++){
        graph[newVertex].push_back(Edges(newVertex,i,0));
    }

    int size = graph.size();
    //cout << size<< endl;
    vector<Edges>edges ;
    for(int i=0 ; i<size ; i++){
        for(auto& edge:graph[i]){
            // cout << edge.u << " " << edge.v << " " << edge.wt << endl;
            edges.push_back(edge);
        }
    }

    vector<int>h(V+1,INF);

    bellmanFord(newVertex,V,edges,h);

    for(int i=0 ; i<size ; i++){
        for(auto& edge:graph[i]){
            if(h[i]!=INF && h[edge.v]!=INF) edge.wt = edge.wt + h[edge.u] - h[edge.v];
        }
    }

    for(int i=1 ; i<V+1 ; i++){
        vector<int>dist(V+1,INF);
        dijkstra(i,V,graph,dist);

        // for(int i=1 ; i<V+1 ; i++){
        // if(dist[i]!=INF) cout << dist[i]<<" ";
        // else cout << "I" <<" ";
        // }cout << endl;

        for(int j=1 ; j<V+1 ; j++){
            if (dist[j]!=INF) shortestpath[i][j] = dist[j] + h[j] -h[i] ;
        }
    }

}


int main(){
    int V, E ;
    cin >> V >> E ;
    vector<vector<Edges>> graph(V+1);
    for(int i=0 ; i<E ; i++){
        int a , b , wt ;
        cin >> a >> b >> wt ;
        //cout << a << " " << b << " " << wt<< endl;
        graph[a].push_back(Edges(a,b,wt));
    }

    vector<vector<int>> shortestpath(V+1,vector<int>(V+1,INF));
    johnsonAlgo(V,E,graph,shortestpath);

    for(int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            if(shortestpath[i][j]==INF) cout << "I" << " " ;
            else cout << shortestpath[i][j] << " " ;
        }cout << endl;
    }
}