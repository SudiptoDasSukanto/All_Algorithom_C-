#include<bits/stdc++.h>
using namespace std;

void articulationPoint(int v ,vector<int> adj[] ,bool visited[] , int disc[],int low[],int parent[] , int &time,bool AP[]){
    
    time++ ;
    visited[v] = true ;
    low[v] = time ;
    disc[v] =time ;
    int child = 0 ;

    for(auto nbr : adj[v]){
        if(nbr == parent[v]) continue;
        else if(visited[nbr] == false){
            child++ ;
            parent[nbr] = v ;
            articulationPoint(nbr,adj,visited,disc,low,parent,time,AP);
            low[v] = min(low[v],low[nbr]);
            if(low[nbr]>=disc[v] && parent[v]!=-1){
                AP[v] = true ;
            }

            if(child>1 && parent[v]==-1){
                AP[v] = true ;
    }

        }else{
            low[v] = min(low[v],disc[nbr]);
        }
    }

    
}

int main(){
    int v , e ;
    cin >> v >> e ;
    vector<int> adj[v] ;

    for(int i=0 ; i<e ; i++){
        int a ,b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool visited[v];
    int disc[v];
    int low[v];
    bool AP[v];
    int parent[v];
    int time = 0 ;
    for(int i=0 ; i<v ; i++){
        visited[i] = false ;
        disc[i] = -1 ;
        low[i] = -1 ;
        AP[i] = false ;
        parent[i] = -1 ;
    }

    for(int i=0 ; i<v ; i++){
        if(visited[i] == false){
            articulationPoint(i,adj,visited,disc,low,parent,time,AP);
        }
    }


    for(int i=0 ; i<v ; i++){
        if(AP[i]){
            cout << i << " " ;
        }
    }cout << endl;
}