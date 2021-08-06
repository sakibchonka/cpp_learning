#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[],int n,int val){
    int dp[val+1];
    dp[0] = 0;
    for(int i=1;i<=val;i++)
        dp[i] = INT_MAX;
    
    for(int i=1;i<=val;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int sub_res = dp[i-coins[j]];
                if(sub_res != INT_MAX && sub_res+1<dp[i]){
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return dp[val];
}

int main(){
    int coins[] = {3,4,1};
    int n = 3,val = 5;

    cout<<minCoins(coins,n,val);

    return 0;
}