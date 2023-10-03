#include<bits/stdc++.h>
using namespace std;

void printPath(vector<vector<int>> &hill , vector<vector<int>> &A , int i , int j, int m){
    if(i==0 || j==0 || j==m+1) return;
    if(A[i-1][j-1]<=A[i-1][j] && A[i-1][j-1]<=A[i-1][j+1]) {
        printPath(hill,A,i-1,j-1,m);
    }
    else if(A[i-1][j]<=A[i-1][j-1] && A[i-1][j]<=A[i-1][j+1]){
        printPath(hill,A,i-1,j,m);
    }
    else {
        printPath(hill,A,i-1,j+1,m);
    }

    cout << i << " " << j << endl;
}

void rock_climbing(vector<vector<int>> &hill , int n , int m){

    vector<vector<int>> A(n+1,vector<int>(m+2));
    for(int i=1 ; i<=m ;i++){
        A[0][i] = 0;
    }

    for(int i=0 ; i<=n ;i++){
        A[i][0] = INT_MAX;
        A[i][m+1] = INT_MAX;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m; j++){
            A[i][j] = hill[i][j]+ min(min(A[i-1][j-1],A[i-1][j]),A[i-1][j+1]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m; j++){
            cout << A[i][j] << " ";
        }cout << endl;
    }

    int x , y ;
    x = n ;
    int mn = INT_MAX ;
    for(int i=1 ; i<=m; i++){
        if(A[n][i]<mn){
            mn = A[n][i];
            y = i ;
        }
    }
    printPath(hill,A,x,y,m);
    //cout << x << y ;
}

int main(){
    int n , m;
    cin >> n >> m ;
    vector<vector<int>> hill(n+1,vector<int>(m+1));

    for(int i = 1 ; i<n+1 ; i++){
        for(int j=1 ; j<m+1 ; j++){
            cin >> hill[i][j];
        }
    }

    rock_climbing(hill,n,m);

}