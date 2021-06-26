#include <iostream>
using namespace std;
//Kadane's Algorithm
void maxSubarraySum(int a[],int n){
    int res = a[0];
    int max_ending = a[0];
    for(int i=1;i<n;i++){
        max_ending=max(max_ending+a[i],a[i]);
        res = max(res,max_ending);
    }
    cout<<res;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    maxSubarraySum(a,n);
}


