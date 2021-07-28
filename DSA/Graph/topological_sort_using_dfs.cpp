#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int>adj[],bool visited[],int s,stack<int>&st){
    visited[s]=true;
    for(int v:adj[s]){
        if(visited[v]==false)
            DFS(adj,visited,v,st);
    }
    st.push(s);
}

void topologicalSort(vector<int>adj[],int V){
    bool visited[V]={false};
    stack<int>st;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFS(adj,visited,i,st);
        }
    }
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cout<<u<<" ";
    }
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int main(){
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);
    
    return 0;
}