#include<bits/stdc++.h>
using namespace std;
void naive_LIS(int input[],int n){
    int length[n],prev[n],path[n];
    length[0] = 0 ;
    prev[0] = -1 ;
    path[0] = 1 ;

    for(int i=1 ; i<n ; i++){
        int len = 0 ,pre = 0 , path_cnt = 0 , p = 1 ;
        for(int j=0 ; j<i ; j++){
            if(input[j]<input[i] && length[j]>=len){
                if(length[j]==len) path_cnt++;
                else path_cnt = 1;
                len = length[j] ;
                pre = j ;
                p = path[j];
            }
        }
        length[i] = len+1 ;
        prev[i] = pre ;
        if(path_cnt>1){
            path[i] = p+path_cnt-1;
        }else{
            path[i] = p ;
        }
    }

    for(int i=0 ; i<n ; i++){
        cout << length[i] <<"  ";
    }cout << endl;

    for(int i=0 ; i<n ; i++){
        cout << prev[i] <<"  ";
    }cout << endl;

    for(int i=0 ; i<n ; i++){
        cout << path[i] <<"  ";
    }cout << endl;
}
int main(){
    int n ;
    cin >> n ;
    int input[n];
    for(int i=0 ; i<n ; i++){
        cin >> input[i];
    }
    naive_LIS(input,n);
}