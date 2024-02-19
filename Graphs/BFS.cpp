
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool printBfs(vector<int>* edgeList , int v, int sv,int en,int* visited){
    visited[sv] = 1;
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
        int val = q.front();
        q.pop();
        cout<<val<<endl;
      if(val == en) return true;
     
        for(int i=0;i<edgeList[val].size();i++){
            if(visited[edgeList[val][i]]!=1){
                q.push(edgeList[val][i]);
                visited[edgeList[val][i]]=1;

            }
        }

    }

    return false;
}


bool BFS(vector<int>* edgeList, int v){
    int sv,en;
    //cout<<"Input start point";
    cin>>sv;
    //cout<<"Input end point";
    cin>>en;

    int* visited = new int[v];
    bool path = false;
    for(int i=0;i<v;i++){
      if(i==sv){
        if(visited[i]!=1)
            path =  printBfs(edgeList,v,i,en,visited);
    }
    }
    return path;
}
int main(){
    int v,e;
    //cout<<"Enter the vertices";
    cin>>v;
    //cout<<"Enter number of edges";
    cin>>e;

    vector<int> edgeList[v+1];
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edgeList[f].push_back(s);
        edgeList[s].push_back(f);
    }

    if(BFS(edgeList,v)) cout<<"true";
    else cout<<"false";

}