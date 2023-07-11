#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int hIdx(vector<int> arr){
    int n= arr.size();
    int idx =-1;
    if(n==1) return arr[0];
    int l =0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m] >= n-m)  {
            idx=max(idx,n-m);
            
            h=m-1;
        }
        else l=m+1;
    }
    return idx;

}

int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    cout<<hIdx(arr);
    
    
    
    return 0;
}