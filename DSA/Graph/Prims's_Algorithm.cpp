#include<bits/stdc++.h>
#define V 4
using namespace std;

int primMST(int graph[V][V]){
    int key[V]; 
    int res = 0;
    fill(key,key+V,INT_MAX);
    bool mSet[V]={false};
    key[0] = 0;
    for(int count=0; count<V; count++){
        int u = -1;

        //find min weight vertex
        for(int i=0; i<V; i++)
            if(!mSet[i] && (u==-1 || key[i]<key[u]))
                u = i;
        mSet[u] = true;
        res += key[u];

        //find adjacent of vertex and update min in key array
        for(int v=0; v<V; v++)
            if(graph[u][v]!=0 && mSet[v]==false)
                key[v] = min(key[v],graph[u][v]);
    }

    return res;
}

int main(){
    int graph[V][V]={   {0,5,8,0},
                        {5,0,10,15},
                        {8,10,0,20},
                        {0,15,20,0}
                    };
    cout<<primMST(graph);
    
    return 0;
}