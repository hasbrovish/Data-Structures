#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

// class Node{
//     public:
//             int vertex;
//             int parent;
//             int wt;
// };

int findMiniVertex(vector<int> wt,vector<int> visited,int v){
    //  wt = {11,12,123,12,13,3};
    //  v = 6;
     int miniVertex = -1;
     for(int i=0;i<v;i++){
        if(!visited[i] && (miniVertex == -1 || wt[i]<wt[miniVertex])){
            miniVertex = i;
        }
        cout<<miniVertex<<"--";
     }
    return miniVertex;
}

void prims(int v,vector<vector<pair<int,int>>> edge,vector<int> visited,vector<int> parent,vector<int> wt){

    // Go to every vertex
    // Find Mini wted vertex
    // explore the neighbours 
    // update wt n parent if necessary
    for(int i=0;i<v;i++){

        int miniVer = findMiniVertex(wt,visited,v);
        cout<<"mini"<<miniVer<<" ";
        visited[miniVer] = 1;
        for(int i=0;i<edge[miniVer].size();i++){
            cout<<edge[miniVer][i].first<<" "<<edge[miniVer][i].second<<endl;
            if(!visited[edge[miniVer][i].first] && wt[miniVer]>edge[miniVer][i].second){
                wt[miniVer] = edge[miniVer][i].second;
                parent[miniVer] = i;
                
            }
        }
    }

    // for(int i=0;i<v;i++){
    //     cout<<i<<" "<<parent[i]<<" "<<wt[i]<<endl;
    // }

}


auto pairComparator = [](const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> edge(v+1);
    vector<int> parent(v+1);
    vector<int> wt(v+1);
    vector<int> visited(v+1);
    //Make Graph input adjacency list
    for(int i=0;i<v;i++){
        parent[i] = -1;
        wt[i] = INT_MAX;
    }
    parent[0] = 0;
    wt[0] = 0;

    for(int i=0;i<e;i++){
        int ft,ed,wt;
        cin>>ft>>ed>>wt;
        edge[ft].push_back(make_pair(ed,wt));
        edge[ed].push_back(make_pair(ft,wt));
    }
    for(int i=0;i<v;i++){
        cout<<i<<":";   
        for(int j=0;j<edge[i].size();j++){
            cout<<edge[i][j].first<<" "<<edge[i][j].second<<" ";
        }     
        cout<<endl;
    }

    // find mst
     prims(v,edge,visited,parent,wt);
}

/*
6 10
0 1 1
0 2 2
1 2 3
1 3 9
1 4 14
2 3 11
2 5 12
3 5 7
3 4 10
5 4 8
*/


