#include<bits/stdc++.h>
using namespace std;

void topological(int v , vector<int>adj[] , bool visited[],stack<int> &st){
    visited[v] = true ;
    for(auto nbr:adj[v]){
        if(visited[nbr]==false){
            topological(nbr,adj,visited,st);
        }
    }

    st.push(v);
    
}

void scc(int v , vector<int>adj[] , bool visited[]){
    visited[v] = true ;
    cout << v << " " ;
    for(auto nbr:adj[v]){
        if(visited[nbr]==false){
            scc(nbr,adj,visited);
        }
    }
    
}

int main(){
    int v , e ;
    cin >> v >> e ;
    vector<int>adj[v];// 0 index
    for(int i=0 ; i<e ; i++){
        int p , q ;
        cin >> p >> q ;
        adj[p].push_back(q);
        //adj[q].push_back(p);
    }

    bool visited[v];
    stack<int> st ;
    for(int i=0 ; i<v ; i++){
        visited[i] = false ;
    }

    for(int i=0 ; i<v ; i++){
        if(visited[i]==false){
            topological(i,adj,visited,st);
        }
    }

    for(int i=0 ; i<v ; i++){
        visited[i] = false ;
    }

    vector<int>tranAdj[v] ;
    for(int i=0 ; i<v ; i++){
        for(auto nbr:adj[i]){
            tranAdj[nbr].push_back(i) ;
        }
    }
    int cnt = 0 ;

    while(!st.empty()){
        int i = st.top();
        st.pop();
         if(visited[i]==false){
            cnt++ ;
            scc(i,tranAdj,visited);
            cout << endl;
        }
        
    }
    //cout << cnt ;

}