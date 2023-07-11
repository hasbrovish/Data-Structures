#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> parent(1000);
class Edge{
    public:
        int start;
        int end;
        int weight;

};

int root(int v){
    // while(v!=parent[v]){
    //     v = parent[v];
    // }
    // return v;
    if(v==parent[v]) return v;
    return root(parent[v]);
}

bool unionFind(int v1,int v2){
    // cout<<v1<<" "<<v2<<endl;
    // cout<<"R1--"<<root(v1)<<" "<<"R2--"<<root(v2)<<endl;
    // if(root(v1)==6) return 6;
        int root1=root(v1);
        int root2=root(v2);
    if(root1!=root2){
        parent[root1]=root2;
    //   for(int i=0;i<9;i++)
    //             cout<<i<<":"<<parent[i]<<" ";
    //         cout<<endl;
        return false;
    }

    return true;
}

int main(){

    int v,e;
    cin>>v>>e;
    vector<Edge> edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].start;
        cin>>edges[i].end;
        cin>>edges[i].weight;
    }

    sort(edges.begin(),edges.end(),[](const Edge& lhs, const Edge& rhs) {
      return lhs.weight < rhs.weight;});
    // cout<<"Edge Wise SOrted Graph"<<endl;
    // for(int i=0;i<e;i++){
    //      cout<<edges[i].start<<" "<<edges[i].end<<" "<<edges[i].weight<<endl;
    // }

    vector<Edge> mst;

    int count=1;
    
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    int temp = 0;

    while(count<v){
        //    if(unionFind(edges[temp].start,edges[temp].end)==6) break;

        if(!unionFind(edges[temp].start,edges[temp].end)){
            // for(int i=0;i<v;i++)
            //     cout<<i<<":"<<parent[i]<<" ";
            // cout<<endl;
            // cout<<"coming";
            mst.push_back(edges[temp]);
            // cout<<"count"<<count<<endl;
            count++;
          
        }
       
            temp++;
            // cout<<"temp"<<temp<<endl;
            // if(edges[temp].start<edges[temp].end)
            // cout<<edges[temp].start<<" "<<edges[temp].end<<endl;
            
    }
    // cout<<"MST-----------------------------";
    for(auto i: mst){
        if(i.start<i.end)
        cout<<i.start<<" "<<i.end<<" "<<i.weight<<endl;
        else
        cout<<i.end<<" "<<i.start<<" "<<i.weight<<endl;
        
    }
//    cout<<endl;

}

/*

9 13
0 3 1
0 1 4
1 2 2
0 2 9
3 2 8
1 5 6
5 6 12
1 6 11
2 6 3
5 7 13
7 8 7
6 8 10
5 8 5

*/
/*
       0
      /  
     3
    / \
   2   1
*/

/*
                        8 --7
                       / \    
                      6   5             8
                     / \                 \   
     3              2   3                 5  
    /              /     \
   0              1       0      

*/