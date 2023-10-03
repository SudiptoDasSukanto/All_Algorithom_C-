#include<bits/stdc++.h>
using namespace std;

void print_LCS(vector<vector<string>> &b,char x[],int i ,int j){
    if(i==0 || j==0) return;
    if(b[i][j]=="--"){
        print_LCS(b,x,i-1,j-1);
        cout << x[i];
    }
    else if(b[i][j]=="-+") print_LCS(b,x,i-1,j);
    else print_LCS(b,x,i,j-1);
}

void LCS(char x[] , char y[]){
    int m = strlen(x);
    int n = strlen(y);
    cout << m << "  " << n << endl;

    vector<vector<int>> c(m,vector<int>(n));
    vector<vector<string>> b(m,vector<string>(n));
    for(int i=0 ; i<m ; i++){
        c[i][0] = 0 ;
    }
    for(int i=0 ; i<n ; i++){
        c[0][i] = 0 ;
    }

    for(int i=1 ; i<m ; i++){
        for(int j=1 ; j<n ; j++){
            if(x[i]==y[j]){
                c[i][j] = c[i-1][j-1]+1 ;
                b[i][j] = "--";
            }
            else if(x[i]!=y[j]){
                if(c[i-1][j]>=c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = "-+";
                }else {
                    c[i][j] = c[i][j-1] ;
                    b[i][j] = "+-";
                }
            }
        }
    }

    for(int i=0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout << c[i][j] << " ";
        }cout << endl;
    }

    for(int i=1 ; i<m ; i++){
        for(int j = 1 ; j<n ; j++){
            cout << b[i][j] << " ";
        }cout << endl;
    }

    print_LCS(b,x,m-1,n-1);

}

int main(){
    char x[] = {'0', 'A', 'B', 'C', 'B', 'D', 'A', 'B' , '\0'};
    char y[] = {'0', 'B', 'D', 'C', 'A', 'B', 'A','\0'};

    LCS(x,y);

}