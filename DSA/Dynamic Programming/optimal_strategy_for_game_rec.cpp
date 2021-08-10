#include<bits/stdc++.h>
using namespace std;

int sol(int arr[],int i,int j){
    if(i+1 == j) 
        return max(arr[i],arr[j]);
    //(i), i+1, ...... j-1, j
    //i, i+1, ...... j-1, (j)

    return max(arr[i]+min(sol(arr,i+1,j-1),sol(arr,i+2,j)),
               arr[j]+min(sol(arr,i,j-2),sol(arr,i+1,j-1)));
}

int main(){
    int n = 4;
    int arr[] = {20, 5, 4, 6};

    cout<<sol(arr, 0, 3);

    return 0;
}