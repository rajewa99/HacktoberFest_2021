/*
 Count the Submatrices
 */
 
 /*
 
 Problem :
A matrix of size  where  and  are integers that denote the number of rows and columns of the matrix respectively. The matrix contains integer elements only. You are given an integer .
Write a program to determine the number of submatrices of this matrix such that the sum of all the elements of a submatrix is divisible by .

Input format:
First line: M, N, and P
*/

#include<bits/stdc++.h>
using namespace std;
 
int subarray_count(const int*a,int n, int p){
 int sum = 0;
 int result = 0;
 int count[p] = {0};
 
 for(int i=0;i<n;i++){
 sum += a[i];
 count[sum%p]++;
 }
 
 for(int i=0;i<p;i++){
 if(count[i]>1)
 result += (count[i] * (count[i] - 1))/ 2;
 }
 result+=count[0];
 return result;
}
 
int submatrices_count(int m,int n,int** a, int p){
 int top_count = 0;
 int temp[m] = {0};
 for(int left=0;left<n;left++){
 //reset vector
 fill(temp,temp+m,0);
 
 for(int right=left;right<n;right++){
 // left and right column
 // calculate sum of along column for all rows
 for(int i=0;i<m;i++)
 temp[i] += a[i][right];
 
top_count += subarray_count(temp, m, p);
 }
 }
 return top_count;
}
 
int main(){
 int m,n,p;
 cin>>m>>n>>p;
 int **a;
 a = new int*[m];
 for(int i=0;i<m;i++)
 a[i] = new int[n];
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++)
 cin>>a[i][j];
 cout<<submatrices_count(m,n,a,p)<<'\n';
 return 0;
}
