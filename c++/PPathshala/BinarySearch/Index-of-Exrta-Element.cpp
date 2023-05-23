#include<bits/stdc++.h>
using namespace std;

int extraIndex(vector<int> a,vector<int> b){

    int n = a.size();
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;

        if(a[m]!=b[m]){
            if(m==0 || (a[m-1]==b[m-1])) return m;
             h = m-1;
        }
        else l=m+1;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int v; cin>>v;
        a.push_back(v);
    }
    for(int i=0;i<n-1;i++){
        int v; cin>>v;
        b.push_back(v);
    }

    cout<<extraIndex(a,b);

}