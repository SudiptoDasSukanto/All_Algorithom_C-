#include<bits/stdc++.h>
using namespace std;

int rod_cut_memorization(int p[],int n,vector<int>&r){
    if(r[n]>=0) return r[n];
    if (n==0) return 0;

    for(int i=1 ; i<=n; i++){
        r[i] = max (r[i],p[i]+rod_cut_memorization(p,n-i,r));
    }

    return r[n];

}

int rod_cut(int p[],int n){
    vector<int> r(n,INT_MIN);
    return rod_cut_memorization(p,n-1,r);
}

int buttom_up_cut_rod(int p[],int n){
    int r[n+1];
    r[0] = 0 ;
    int q ;
    for(int j=1 ; j<=n ; j++){
        q  = INT_MIN;
        for(int i=1 ; i<=j ; i++){
            q = max(q,p[i]+r[j-i]);
        }
        r[j] = q ;
    }

    return r[n];
}

int main(){
    int n ;
    cin >> n ;
    int p[n];
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
    }

    cout << rod_cut(p,n) << endl;

    cout << buttom_up_cut_rod(p,n-1);
}