#include<bits/stdc++.h>
using namespace std;

void KClosestElements(int arr[], int n, int x, int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<k; i++)
        pq.push({abs(arr[i]-x),i});
    
    for(int i=k; i<n; i++){
        int diff = abs(arr[i]-x);
        if(pq.top().first > diff){
            pq.pop();
            pq.push({diff,i});
        }
    }
    while(pq.empty()==false){
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }
}

int main(){
    int n = 5;
    int arr[n] = {10, 15, 7, 3, 4};
    int x = 8;
    int k =3;
    KClosestElements(arr,n,x,k);

    return 0;
}