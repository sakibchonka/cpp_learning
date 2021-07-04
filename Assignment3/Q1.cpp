#include<bits/stdc++.h>
using namespace std;

//a1[] = {11, 1, 13, 21, 3, 7}
// a2[] = {11, 3, 7, 1}
bool isSubset(int *a1, int *a2, int n, int m){
    if(m>n) return false;
    sort(a1,a1+n);
    sort(a2,a2+m);
    for(int i=0;i<m;i++){
        if(a2[i]!=a1[i])
            return false;
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a1[n];
    int a2[m];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    for(int i=0;i<m;i++){
        cin>>a2[i];
    }
    cout<<isSubset(a1,a2,n,m);
}