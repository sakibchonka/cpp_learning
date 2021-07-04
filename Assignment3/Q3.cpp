#include<bits/stdc++.h>
using namespace std;

int findMax(int *a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max) max=a[i];
    }
    return max;
}
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
int minCapacity(int *weights, int n, int days){
    int min_cap = findMax(weights,n);
    while(true){
        int sum=0;
        int d=1;
        for(int i=0;i<n;i++){
            if(d>days){
                break;
            }
            if(sum+weights[i]<=min_cap){
                sum+=weights[i];
            }else{
                sum=weights[i];
                d++;
            }
        }
        if(d==days)
            return min_cap;
        else  
            min_cap++;
    }
}

int main(){
    int n, days;
    cin>>n>>days;
    int weights[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    cout<<minCapacity(weights,n,days);
}