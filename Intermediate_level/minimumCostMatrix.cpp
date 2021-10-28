#include<iostream>
using namespace std;

int getMinPath(int r,int c,int m,int n, int **matrix){
if(r==m-1 && c==n-1)
    return matrix[r][m];
int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
if(c+1<n)
    c1=getMinPath(r,c+1,m,n,matrix);
if(r+1<m)
    c2=getMinPath(r+1,c,m,n,matrix);
if(r+1<m && c+1<n)
    c3=getMinPath(r+1,c+1,m,n,matrix);
    return matrix[r][c]+min(c1,min(c2,c3));
}

int main(){
int m,n;
cin>>m>>n;
int **matrix=new int*[m];
for(int i=0;i<m;i++){
    matrix[i]=new int[n];
    for(int j=0;j<n;j++)
        cin>>matrix[i][j];
}
cout<<getMinPath(0,0,m,n,matrix);
}
