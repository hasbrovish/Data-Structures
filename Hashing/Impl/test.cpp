#include<bits/stc++.h>
using namespace std;
def mod 10000;

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> points(n);
    unordered_map<int,int> x_map;
    unordered_map<int,int> y_map;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points = {x,y};
        x_map[x]++;
        y_map[y]++;
    }
    int ans =0;
    for(auto p:points){
        ans = (ans%mod + (x_map[p[0]]-1)%mod* (y_map[p[1]]-1)mod)%mod;
    }
    cout<<ans;
}

-----------------------------------



question assetment 
DSA -> concepts
core subject
system desing --> expiriece
project ex : lat 4 year works
---
practise stredegy
5-6 months
right now like reading interviews 
