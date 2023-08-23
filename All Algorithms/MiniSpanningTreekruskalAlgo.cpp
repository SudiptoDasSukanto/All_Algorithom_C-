#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10 ;
int parent[N];
int Rank[N];

void make(int v){
    parent[v] = v ;
    Rank[v] = 1 ;
}

int find(int v){
    if(v==parent[v]) return v ;
    //return parent[v] = find(parent[v]);// Path compression
    return parent[v];
}

void Union(int a , int b){
    a = find(a);
    b = find(b);
    if(a!=b) {
        if(Rank[a]>Rank[b]) parent[b] = a ; // Rank base Union
        else if(Rank[a]<Rank[b]) parent[a] = b ;
        else{
            parent[b] = a ;
            Rank[a]+=Rank[b];
        }
    }
}

int main(){
    int v , e;
    cin >> v >> e ;
    vector<pair<int,pair<int, int>>> edges;
    for(int i=0 ; i<e ; i++){
        int w,p,q ;
        cin >> p>>q>>w;
        edges.push_back({w,{p,q}});
    }

    sort(edges.begin(),edges.end());
    int total_weight = 0;
    for(int i=1 ; i<=v ; i++){
        make(i) ;
    }

    for(auto edge : edges){
        int w = edge.first ;
        int u = edge.second.first ;
        int v = edge.second.second ;
        if(find(u)!=find(v)){
            total_weight+=w ;
            Union(u,v);
            cout << u << " " << v << endl;
        }
    }

    cout << total_weight << endl;

}