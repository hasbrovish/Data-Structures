#include<iostream>
#include<vector>
#include<queue>
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
int* bfs(const vector<int>* adjList, int n , int sv){
    int* visited = new int[n+1];
    visited[sv] = 1;
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
        int val = q.front();
        //cout<<val<<endl;
        q.pop();
          for (int neighbor : adjList[val]) {
            if (visited[neighbor] != 1) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    } 
    return visited;
}

bool isConnected(const vector<int>* adjList, int n){
    int* visited = bfs(adjList,n,0);
    for(int i=0;i<n;i++){
        if(!visited[i])
            return false;
    }
    delete[] visited;
    return true;
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<int>* adjList = getGraph(n,e);
    printGraph(adjList,n);   
    bool res = isConnected(adjList,n);
    delete[] adjList;
    //cout<<"path:";
    //Ref: https://www.geeksforgeeks.org/ios-manipulators-boolalpha-function-in-c/
    cout<<boolalpha<<res<<endl;
    //for(int i=0;i<n;i++)
   

}