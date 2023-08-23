#include<bits/stdc++.h>
using namespace std;

void bridges(int v , int parent , vector<int> adj[] ,int disc[] , int low[],bool visited[] ,int &time){
    visited[v] = true ;
    time++ ;
    disc[v] = time ;
    low[v] = time ;
    for(auto p:adj[v]){
        if(p==parent){
            continue;
        }else if(visited[p]==false){
            parent =  v ;
            bridges(p,parent , adj,disc,low,visited,time);

            low[v] = min(low[v],low[p]);
            if(low[p]>disc[v]){
                cout << p << " " << v << endl;
            }
        }else{
            low[v] = min(low[v],disc[p]);
        }
    }
}

int main(){
    int v ,e;
    cin >> v >> e;
    vector<int> adj[v];

    for(int i=0 ; i<e ; i++){
        int a , b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a) ;
    }

    int disc[v];
    int low[v];
    bool visited[v] ;
    int parent = -1 ;
    int time = 0 ;

    for(int i=0 ; i<v ; i++){
        disc[i] = -1 ;
        low[i] =  -1 ;
        visited[i] = false ;
    }

    for(int i=0 ; i<v ; i++){
        if(visited[i] == false){
            bridges(i,parent , adj,disc,low,visited,time);
        }
    }

}