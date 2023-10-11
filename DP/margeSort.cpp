#include<bits/stdc++.h>
using namespace std;

void marge(int arr[],int s , int mid , int e,int &counting){
    int ll = mid-s+1 ;
    int rl = e-mid ;
    int leftArray[ll];
    int rightArray[rl];
    int idx=s ;

    for(int i=0 ; i<ll ; i++){
        leftArray[i] = arr[idx++] ;
    }
    for(int i=0 ; i<rl ; i++){
        rightArray[i] = arr[idx++] ;
    }

    int idxl=0 , idxr=0 ;
    int mainIdx = s ;
    while(idxl<ll && idxr<rl){
        if(leftArray[idxl]<rightArray[idxr]) {
            arr[mainIdx++] = leftArray[idxl++];
        }else{
           arr[mainIdx++] = rightArray[idxr++]; 
           counting+=(ll-idxl);
        }

    }

    while(idxl<ll){
        arr[mainIdx++] = leftArray[idxl++];
    }

    while(idxr<rl){
        arr[mainIdx++] = rightArray[idxr++];
    }
    


}

void margesort(int arr[],int s , int e, int &counting){
    if(s>=e) return;
    

    int mid = (s+e)/2 ;
    margesort(arr,s,mid,counting);
    margesort(arr,mid+1,e,counting);
    marge(arr,s,mid,e,counting);

}

int main(){
    int n ;
    cin >> n ;
    int arr[n] ;
    for (int i =0 ; i<n ; i++){
        cin >> arr[i] ;
    }
    int counting = 0 ;
     margesort(arr,0,n-1,counting);
     cout << counting << endl;

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " " ;
    }
}