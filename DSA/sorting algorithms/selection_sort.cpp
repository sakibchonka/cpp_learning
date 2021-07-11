#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void selection_sort(int arr[],int n){
    int min_idx;
    for(int i=0;i<n-1;i++){
        min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        swap(&arr[min_idx],&arr[i]);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {64,25,12,22,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    printArray(arr,n);
    return 0;
}