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

void optimalSolution1(int input[],int n){
    vector<int> ans ;
    int p = -1 ;
    
    for(int i=1 ; i<n ; i++){
        if(input[i]>input[i-1]){
            ans.push_back(input[i]);
            p++;
        }else{
            if(input[i]>input[i-2]){
                ans[p] = input[i];
            }else continue ;
        }
    }
    for(int i=0 ; i<=p ; i++){
        cout << ans[i] << " ";
    }cout << endl;
}

int binarySearch(vector<int>&arr ,int s , int e , int target){
    int left = s ;
    int right = e ;
    while(left<right){
        int mid = (left+right)/2 ;
        if(arr[mid]<=target) left = mid+1 ;
        else right = mid ;
    }

    return left ;
    
}

void optimalSolution2(int input[],int n){
    vector<int> ans(n,INT_MAX) ;
    ans[0] = INT_MIN ;
    
    for(int i=1 ; i<n ; i++){
        int l = binarySearch(ans,0,n,input[i]);
        //int l = upper_bound(ans.begin(),ans.end(),input[i]);
        if(ans[l-1]<input[i] && ans[l]>input[i]){
            ans[l] = input[i];
        }
    }

    for(int i=1 ; i<n ; i++){
        if(ans[i]!=INT_MAX)cout << ans[i] << " ";
    }
    
}

int main(){
    int n ;
    cin >> n ;
    int input[n];
    for(int i=0 ; i<n ; i++){
        cin >> input[i];
    }
    naive_LIS(input,n);
    optimalSolution2(input,n);
}