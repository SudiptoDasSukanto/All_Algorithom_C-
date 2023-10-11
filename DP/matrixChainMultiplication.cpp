#include<bits/stdc++.h>
using namespace std;

int MEMORIZED_MATRIX_CHAIN(int p[],int n)
{
    int m[n][n] ;
    //vector<vector<int>> m(n+1,vector<int>(n+1));
    vector<vector<int>> s(n+1,vector<int>(n+1));

    for(int i=1 ; i<n ;i++){
        m[i][i] =  0 ;
    }
    int q = 0 ;

    for(int l=2 ; l<n ;l++){
        for(int i=0 ; i<n-l+1 ; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i ; k<=j-1 ; k++){
                q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j] = q ;
                    s[i][j] = k ;
                }
            }
        }
    }

    return m[1][n-1];

}

int main(){
    int p[] = { 1, 2, 3, 4};
    int n = sizeof(p)/sizeof(p[0]);

    cout <<MEMORIZED_MATRIX_CHAIN(p,n);

}