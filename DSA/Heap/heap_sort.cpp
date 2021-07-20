#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[i])
        largest = l;
    if(r<n && arr[r]>arr[largest])  
        largest = r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(arr,n,i);
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {12,3,44,56,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,n);
    cout<<"sorted array is \n";
    printArray(arr,n);
}