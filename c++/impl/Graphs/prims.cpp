#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

class Node{
    public:
            int vertex;
            int parent;
            int wt;
};
// bool comparator(int a,int b){
//     return a<b;
// }
auto pairComparator = [](const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<map<int,int>> edge(v+1);
    vector<pair<int,int>> primList(v);
    vector<pair<int,int>> vData(v);
    for(int i=0;i<e;i++){
        int ft,ed,wt;
        cin>>ft>>ed>>wt;
        edge[ft][ed]= wt;
        edge[ed][ft] = wt;
    }

    primList[0].first = 0;
    primList[0].second = -1;
    vData[0].first = -1;
    vData[0].second = 0;
    
    for(int i=1;i<v;i++){

        primList[i].first = i;
        primList[i].second = INT_MAX;
        vData[i].first = -1;
        vData[i].second = INT_MAX;
    }

    vector<int> visited(v+1,0);

    // sort(primList.begin(),primList.end(),pairComparator);
    // for(int i=0;i<primList.size();i++){
    //     cout<<i<<":"<<primList[i].first<<" "<<primList[i].second<<endl;
    // }

    // int count = 0;
    // int minelem = 0;
    // int minelemWt = 0;
    // while(count<v){
    //      vector<pair<int,int>> temp;
    //     if(!visited[minelem]){
    //     for(auto i = edge[minelem].begin();i!=edge[minelem].end();i++){
    //         if(!visited[i->first]){
    //         if(i->second < vData[i->first].second)
    //         {   
    //             temp.push_back(make_pair(i->first,i->second));
    //             vData[i->first].first = i->first;
    //             vData[i->first].second = i->second;
    //         }
    //         }
    //     }
    //     visited[minelem] = 1;
    //     }

    //     sort(temp.begin(),temp.end(),pairComparator);
    //      if(!temp.empty()){
    //         minelem = temp[0].first;
    //         count++;
    //     }
    // }
    // cout<<"MST"<<endl;
    // for(int i=0;i<v;i++){
    //     cout<<i<<" "<<vData[i].first<<" "<<vData[i].second<<endl;
    // }
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


