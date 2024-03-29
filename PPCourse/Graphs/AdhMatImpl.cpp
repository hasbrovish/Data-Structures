//Graph can be implemented in two ways:
//1: Adjacency Matrix
//2: Adjacency List

//Adjacency Matrix
//Input will be given m,n => vertex . edges

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    int adj[n+1][n+1];
    //Fill comes under algorithm to intialise every element with 0;
    fill(&adj[0][0],&adj[0][0]+ (m+1)*(n+1),0);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        //Undirected : Bidirectional entry
        adj[u][v]=1;
        adj[v][u]=1;
        //Undirected wt
        // adj[u][v]= wt;
        // adj[v][u]= wt;
        // Directed
        // adj[u][v]= wt;
        //Only a single entry 

    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

