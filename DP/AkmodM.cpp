#include<bits/stdc++.h>
using namespace std;

long long modPow(long long base ,long long exponent , long long Modular){
    if(exponent==0) return 1 ;
    else if(exponent%2==0){
        long long tempAns = modPow(base,exponent/2,Modular);
        return (tempAns*tempAns)%Modular;
    }else{
        long long tempAns = modPow(base,exponent-1,Modular);
        return (base*tempAns)%Modular;
    }
}

int main(){
    long long A , k , M;
    cin >> A >> k >> M;

    cout << modPow(A,k,M);
}