/*
    - makeset()
    - find() -> same set or same component
    - union() -> merge to same set
This is the implementation of union find algortithm , 
with union rank and path compression.
*/
/*
Representation of a single component can be like a node
Node{
    int size; -- rank
    int val;
    Node parent;
}
or 

index can be vertex and maintain wo array for rank and parent pointers
*/

#include<iostream>
#include<vector>
using namespace std;

int v;

void makeSet(vector<int>  &parent,vector<int>  &_size){

    for(int i=0;i<v;i++){

        parent[i] = i;
        _size[i] = 1;

    }

}

int find(int n,vector<int>  &parent,vector<int>  &_size){

    if(parent[n] == n)
        return n;
    else
        return parent[n] = find(parent[n],parent,_size); //Path compression will directly save the root ,
                                            // not the immidiate parent in parent array.
}


void _union(int v1,int v2,vector<int>  &parent,vector<int>  &_size){

    int root1 = find(v1,parent,_size);
    int root2 = find(v2,parent,_size);

    if(root1 == root2)
        return;
    if(_size[root1]>_size[root2]){
        parent[root2] = root1;
        _size[root1] += _size[root2];
        }
    else{
        parent[root1] = root2;
        _size[root2] += _size[root1];
    }        
}
bool same_component(int s1,int s2,vector<int>  &parent,vector<int>  &_size){
    return (find(s1,parent,_size) == find(s2,parent,_size));
}

int main(){

     v=9;
    // cout<<"Enter num of elems";
    // cin>>v;
    vector<int> parent(v);
    vector<int> _size(v);
    makeSet(parent,_size);
    _union(1,2,parent,_size);
    
    _union(3,5,parent,_size);
    _union(7,8,parent,_size);
    _union(3,6,parent,_size);
    _union(6,1,parent,_size);
    _union(4,7,parent,_size);
    _union(1,4,parent,_size);
         
    cout<<same_component(1,3,parent,_size);
    cout<<same_component(1,4,parent,_size); 
    

}