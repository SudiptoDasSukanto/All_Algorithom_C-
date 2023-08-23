#include<bits/stdc++.h>
using namespace std;
bool graph[100][100];

bool isSafe(int e , int path[]  ,int pos){
    //cout << "SUkantp"<< e <<endl;
    if(graph[path[pos-1]][e]==0) return false ;

    for(int i=0 ; i<pos ; i++){
        if(e==path[i]) return false ;
    }

    return true ;
}

bool Hamiltonianpath(int v , int path[] ,int pos){

    if(pos==v){
        if(graph[path[pos-1]][path[0]]){
            return true ;
        }
        else return false ;
    }
    

    for(int i=1 ; i<v ; i++){
        if(isSafe(i,path,pos)==true){
            //cout << i << endl;
            path[pos] = i ;
            if(Hamiltonianpath(v,path,pos+1)) return true;

            path[pos] = -1 ;
        }
    }

    return false ;
}

int main() {
    int v , e ;
    cin >> v >> e  ;
    for(int i=0 ; i<100 ; i++){
        for(int j=0 ; j<100 ; j++){
            graph[i][j] = 0 ;
        }
    }
    for(int i=0 ; i<e ;i++){
        int p , q ;
        cin >> p >> q;
        graph[p][q] = 1;
        graph[q][p] = 1;
    }


    int path[v] ;
    for(int i=0 ; i<v ; i++){
        path[i] =-1 ;
    }
    path[0] = 0 ;
    int pos = 1 ;

    if(Hamiltonianpath(v,path,pos)==false){
        cout << "Hamiltonian Cycle not exist\n";
    }else{
        for(int i=0 ; i<v ; i++){
            cout << path[i] << " " ;
        }cout << path[0] << endl;
    }


}