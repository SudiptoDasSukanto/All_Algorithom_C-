#include<bits/stdc++.h>
using namespace std;

bool isBiConnected(int v , vector<int> adj[] , int disc[] , int low[] , int parent[] , bool visited[] , int &time){
    int child = 0 ;
    visited[v] = true ;
    time ++ ;
    disc[v] = low[v] = time;
    for(auto nbr:adj[v]){
        if(nbr==parent[v]) continue;
        else if(visited[nbr]==false){
            child++ ;
            parent[nbr] = v ;
            if(isBiConnected(nbr ,adj, disc,low ,parent,visited,time)) return true ;
            
            low[v] = min(low[v],low[nbr]);
            if(parent[v] != -1 && low[nbr]>=disc[v]){
                return true ;
            }

            if(parent[v] == -1 && child>1) return true ;

        }else{
            low[v] = min(low[nbr] , disc[v]);
        }
        
    }

    return false ;
}

int main(){
    int v ,e ;
    cin >> v >> e ;
    vector<int> adj[v];
    for(int i=0 ; i<e ; i++){
        int a , b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int disc[v];
    int parent[v];
    int low[v];
    bool visited[v];
    int time = 0 ;
    for(int i=0 ; i<v ; i++){
        disc[i] = -1 ;
        parent[i] = -1 ;
        low[i] = -1 ;
        visited[i] = false ;
    }
    bool result  ;
    int isConnect = 0;
    for(int i=0 ; i<v ; i++){
        
        if(visited[i] == false){
            isConnect++ ;
             result = isBiConnected(i ,adj, disc,low ,parent,visited,time);
        }
           
    }

    if(result==false && isConnect==1){
        cout << "Grapg is Bi-Connected " << endl;
    }else cout << "Graph is not Bi-Connected" << endl;

}