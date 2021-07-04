#include<bits/stdc++.h>
using namespace std;
//6 13
//1 4 45 6 10 8
bool tripletSum(int *arr,int n,int X){
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==X)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    int n,X;
    cin>>n>>X;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<tripletSum(arr,n,X);
}