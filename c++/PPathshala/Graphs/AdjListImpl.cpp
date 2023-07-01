#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter vetices of graph";
    cin>>m;
    cout<<"Enter edges of graph";
    cin>>n;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<n;i++){
        int v,u;
        cin>>v>>u;
        //Undirected 
        //adj[v].push_back(u);
        //adj[u].push_back(v);
        //Weighted undirected graph
        int wt;
        cin>>wt;
        adj[v].push_back(make_pair(u,wt));
        adj[u].push_back(make_pair(v,wt));
        //jut one push for directed graph.
    }
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(auto j:adj[i]) cout<<j.first<<":"<<j.second<<" ";
        cout<<endl;
    }
}



