#include<bits/stdc++.h>
using namespace std;
#define n 5

int parent[n];
int rank_[n];


void initialize(){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank_[i] = 0;
    }
}

int find(int x){
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}

void unions(int x,int y){
    int x_rep = find(x);
    int y_rep = find(y);
    if(x_rep==y_rep) return;
    if(rank_[x_rep]<rank_[y_rep])
        parent[x_rep] = y_rep;
    else if(rank_[y_rep]<rank_[x_rep])
        parent[y_rep] = x_rep;
    else{
        parent[y_rep] = x_rep;
        rank_[x_rep]++;
    }
}

int main(){
    initialize();

    unions(3,4);
    unions(2,3);
    unions(1,2);
    unions(0,1);


    cout<<parent[3]<<endl;
    cout<<rank_[3]<<endl;

    return 0;
}