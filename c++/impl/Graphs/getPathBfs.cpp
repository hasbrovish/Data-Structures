#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

vector<int>* getGraph(int n,int e){

//     Neche wala line se local array return kr rhe hain funtion se ye gala hai
//     , cause funtion over hone ke bad/
//  Warning: In function 'int* fun()': 6:8: warning: address of local variable
// 'arr' returned [-Wreturn-local-addr] int arr[100];
//         ^
// The above program is WRONG. It may produce values of 10 or 20 as output or
//     may produce garbage values or may crash. The problem is, that we return
//     the address of a local variable which is not advised as local variables
//     may not exist in memory after the function call is over. 
//vector<int>     adjList[n+1];

//REF : https://www.geeksforgeeks.org/how-to-return-a-local-array-from-a-cpp-function/

    // static vector<int> adjList[1000+6];
    vector<int>* adjList = new vector<int>[n+1];
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }
    return adjList;

}

void printGraph(vector<int>* adjList, int n){
for(int i=0;i<n;i++){
        cout<<i<<":";
        for(auto j : adjList[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

vector<int>  getPathBfs(map<int,int> mp,int sv, int en){

    vector<int> res;
    int start = en;
    res.push_back(en);
    while(start!=sv){
        res.push_back(mp[start]);
        start = mp[start];
    }
   // res.push_back(sv);
  return res;
}

//Function to get
vector<int> bfs(vector<int>* adjList, int n , int sv , int en){
    int* visited = new int[n+1];
    visited[sv] = 1;
    queue<int> q;
    map<int,int> mp;
    q.push(sv);
    int flag=-1;
    while(!q.empty()){
        int val = q.front();
        //cout<<val<<endl;
        q.pop();
        for(int i=0;i<adjList[val].size();i++){
          ///  cout<<adjList[val][i]<<" ";
            if(visited[adjList[val][i]]!=1){
            visited[adjList[val][i]] = 1;
            q.push(adjList[val][i]);
            mp[adjList[val][i]] = val;
            }
            if(adjList[val][i] == en)
               { 
                flag=en; 
                break;
                }
        }
        if(flag==en) break;

    }
   // cout<<flag;
     if(flag==-1) return vector<int> {};
    delete[] visited;
    return getPathBfs(mp,sv,en);
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<int>* adjList = getGraph(n,e);
   // printGraph(adjList,n);   
    int sv,en;
   // cout<<"Enter start" ;
    cin>>sv;
    //cout<<"Enter end";
    cin>>en;
    vector<int> res = bfs(adjList,n,sv,en);
    //cout<<"path:";
    for(auto i:res)
    {
        cout<<i<<" ";
    }

    //for(int i=0;i<n;i++)
    delete[] adjList;

}