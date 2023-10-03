#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&p){
    
}

void knapsack(vector<vector<int>>&list,int n , int w){
    vector<vector<int>>p(n+1,vector<int>(w+1));
    for(int i=0 ; i<=w ;i++) p[0][i] = 0;
    for(int i=1 ; i<=n ;i++) p[i][0] = 0;

    for(int i=1 ; i<=n ;i++){
        for(int j=1 ; j<=w ;j++){
            if(j-list[i][0]<0) p[i][j] = p[i-1][j] ;
            else p[i][j] = max(list[i][1]+p[i-1][j-list[i][0]],p[i-1][j]);
        }
    }

    for(int i=0 ; i<=n ;i++){
        for(int j=0 ; j<=w ;j++){
            cout << p[i][j] << " ";
        }cout << endl;
    }
}

int main(){
    int n , w;
    cin >> n >> w;
    vector<vector<int>>list(n+1,vector<int>(2));
    for(int i=1 ; i<=n ; i++){
        int w , v ;
        cin >> w >> v ;
        list[i][0]=w;
        list[i][1]=v;
    }
    for(int i=1 ; i<=n ; i++){
        cout << i << " " <<list[i][0] << " " << list[i][1] << endl;
    }
    knapsack(list,n,w);
}