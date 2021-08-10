#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[],int n){
    int dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++)
        dp[i] = INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]+j >= i && dp[j]!=INT_MAX){
                    dp[i] = min(dp[i],dp[j]+1);
                    break;
            }
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {3,4,2,1,2,1};
    int n = 6;
    cout<<minJumps(arr,n);

    return 0;
}