#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(int** edge , int n ,int sv, int* visited){
    visited[sv] =1;
    cout<<sv<<endl;
    for(int i=0;i<n;i++){
        if(sv==i) continue;
        if(edge[sv][i] ==1 && visited[i]!=1){
            print(edge,n,i,visited);
        }
    }
}

void dfsRecursive(vector<int> *edgeList , int n,int sv ,int* visited){
    visited[sv]=1;
    cout<<sv<<endl;
    for(int i=0;i<edgeList[sv].size();i++){
        if(visited[edgeList[sv][i]]!=1){
            dfsRecursive(edgeList,n,edgeList[sv][i],visited);
        }
    }
}

void dfsIterative(vector<int> *edgeList , int n,int sv ,int* visited){
    stack<int> st;
    st.push(sv);
    visited[sv]=1;
    //cout<<sv<<endl;
    while(!st.empty()){
        
        int val = st.top();
        st.pop();
        cout<<val<<endl;
    for(int i=0;i<edgeList[val].size();i++){
        if(visited[edgeList[val][i]]!=1){
            st.push(edgeList[val][i]);
            visited[edgeList[val][i]]=1;
        }
    }
    }
    
}

int main()
{
    int n ;
    int e;
    cout<<"Input the vertices";
    cin>>n;
    cout<<"Input the edges";
    cin>>e;
    int** edge = new int*[n+1];
    vector<int> edgeList[n+1];
    for(int i=0;i<n+1;i++){
         edge[i] = new int[n+1];
         for(int j=0;j<n+1;j++)
            edge[i][j] = 0;
       //  edgeList.push_back(vector<int>);   
    }
    cout<<"Input the edges pairs";
    for(int i=0;i<e;i++){       
        int f,s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
        edgeList[f].push_back(s);
        edgeList[s].push_back(f);
        }
    for(int i=0;i<=n;i++){
        cout<<i<<":";
        for(int j=0;j<edgeList[i].size();j++){
            cout<<edgeList[i][j]<<" ";
        }
        cout<<endl;
    }
    int* visited = new int[n];
    cout<<"Input the starting point for traversal";
    int sv; cin>>sv;
    cout<<"DFS travesal";   
    //print(edge,n,sv,visited);
    visited[0]=1;
    visited[sv]=1;
    //dfsRecursive(edgeList,n,sv,visited);
    dfsIterative(edgeList,n,sv,visited);
    for(int i=0;i<n;i++){
        delete[] edge[i];     
    }   
}
/*
Complexity analysis:
*/