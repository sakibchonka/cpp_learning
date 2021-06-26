#include<bits/stdc++.h>
using namespace std;

void deleteDupl(int arr[],int n){
    int a[n];
    a[0]=arr[0];
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=a[j]){
            a[j+1]=arr[i];
            j++;
        }
    }
    for(int i=0;i<j+1;i++)
        cout<<a[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deleteDupl(a,n);
}