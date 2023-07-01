#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> getPath(vector<int> *edgeList , int n,int sv,int en,int* visited){
    vector<int> vec;
    if(sv == en){
        vec.push_back(en);
         return vec;
    }
    
    for(int i=0;i<edgeList[sv].size();i++){
        if(visited[edgeList[sv][i]]!=1){
            visited[edgeList[sv][i]]= 1;
            if(vec.size()==0)
            vec = getPath(edgeList,n,edgeList[sv][i],en,visited);
        }
    }
    if(vec.size()>0)
        vec.push_back(sv);
    return vec;
}


int main()
{
    int n ;
    int e;
    //cout<<"Input the vertices";
    cin>>n;
    //cout<<"Input the edges";
    cin>>e;
    
    vector<int> edgeList[n+1];
    //cout<<"Input the edges pairs";
    for(int i=0;i<e;i++){       
        int f,s;
        cin>>f>>s;
        edgeList[f].push_back(s);
        edgeList[s].push_back(f);
        }
    for(int i=0;i<=n;i++){
      //  cout<<i<<":";
        for(int j=0;j<edgeList[i].size();j++){
        //    cout<<edgeList[i][j]<<" ";
        }
        //cout<<endl;
    }
    int* visited = new int[n];
    int sv; 
    cin>>sv;
    int en; cin>>en;   
    visited[sv]=1;
    vector<int> res = getPath(edgeList,n,sv,en,visited);
  //  if(res.size()>1)
    //    res.push_back(sv);
//   cout<<"res:";
    for(auto i : res) cout<<i<<" ";
}