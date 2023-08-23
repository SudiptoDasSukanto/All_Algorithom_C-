#include<bits/stdc++.h>
using namespace std;

void DFS(int v , vector<int>adj[] ,bool visited[]){
    visited[v] = true ;
    for(auto nbr : adj[v]){
        if(visited[nbr] == false) DFS(nbr,adj,visited);
    }
}

bool isConnected(int v , int e , vector<int>adj[]){
    bool visited[v];
    for(int i=0 ; i<v ; i++){
        visited[i] = false ;
    }
    int p ;

    for(p=0 ; p<v ; p++){
        if(adj[p].size()!=0) break;
    }

    if(p==v) return true ;

    DFS(p,adj,visited);

    for(int i=0 ; i<v ; i++){
        if(visited[i]==false){
            if(adj[i].size()!=0){
                return false;
            }
        }
    }

    return true ;

}

int isEularian(int v , int e , vector<int>adj[]){
    if(isConnected(v,e,adj)==false){
        return 0;
    }

    int odd = 0 ;
    for(int i=0 ; i<v ; i++){
        if(adj[i].size()&1) odd++ ;
    }

    if(odd==0){
        return 2 ;// Eularian
    }else if(odd == 2) return 1 ;//semi-Eularian
    else return 0 ;
}

int main(){
    int v , e ;
    cin >> v >> e ;
    vector<int>adj[v];
    for(int i=0 ; i<e ; i++){
        int p , q ;
        cin >> p >> q ;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    int result = isEularian(v,e,adj);

    if(result==0) cout << "Graph has not Eulerian \n";
    else if(result==1) cout << "Graph has a Eulerian Path\n";
    else cout << "Graph has a Eulerian cycle\n";

}