#include<bits/stdc++.h>
using namespace std;
//dutch national flag problem
void segregateNums(int *a,int n){
    int low=0,mid=0,high=n-1;
    while(mid<high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}
int main(){
    int a[] = {0,1,0,1,0,0,2,2,1,1,0,2,2,1,0,1};
    int size = sizeof(a)/sizeof(a[0]);
    segregateNums(a,size);
    for(int e:a)
        cout<<e<<" ";
}