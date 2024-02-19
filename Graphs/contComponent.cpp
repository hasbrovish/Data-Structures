#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>* getGraph(int n,int e){
    vector<int>* adjList = new vector<int>[n+1];
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }
   
    return adjList;

}

void printGraph(const vector<int>* adjList, int n){
    for(int i=0;i<n;i++){
            cout<<i<<":";
            for(auto j : adjList[i])
                cout<<j<<" ";
            cout<<endl;
        }
}

//Function to get
vector<int> bfs(const vector<int>* adjList, int n , int sv,vector<int> &visited){
    vector<int> cmpt;
    visited[sv] = 1;
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
        int val = q.front();
        cmpt.push_back(val);
        //cout<<val<<endl;
        q.pop();
          for (int neighbor : adjList[val]) {
            if (visited[neighbor] != 1) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    } 
    return cmpt;
}

 vector<vector<int>> getContCmpnt(const vector<int>* adjList, int n){
    vector<int> visited(n+1); 
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            vector<int> cmp = bfs(adjList,n,i,visited);
            // cout<<"comp"<<endl;
            // for(auto i : cmp ) cout<<i<<" ";
            res.push_back(cmp);
        }
     
    }
    for(int i=0;i<res.size();i++){
            sort(res[i].begin(),res[i].end());
    }
    return res;
   
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<int>* adjList = getGraph(n,e);
    //printGraph(adjList,n);   
    vector<vector<int>> res = getContCmpnt(adjList,n);
    delete[] adjList;
    // cout<<"res";
    for(int i=0;i<res.size();i++){
        for(auto j : res[i])
            cout<<j<<" ";
    cout<<endl;
    }
  
}
