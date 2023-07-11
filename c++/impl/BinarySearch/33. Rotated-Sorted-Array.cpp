// Q: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Medium
// Rotated Sorted Array


#include<bits/stdc++.h>
using namespace std;
int pivotDetection(vector<int> &arr){
    int n = arr.size();
    int l=0,h = n-1;

    while(l<=h){
        int m = (l+h)/2;

        if(arr[m]<=arr[n-1])
        h = m-1;
        else{
            if(arr[m]>arr[m+1])
            return m;
            l = m+1;
        }
    }
return n-1;
}

int bsearch(vector<int> arr, int l , int h, int key){

    while(l<=h){
        int m=(l+h)/2;

        if(arr[m] == key){
            return m;
        }
        else if (arr[m]<key){
            l=m+1;
        }
        else 
            h = m-1;

    }
    return -1;

}

int main(){
int n;
cin>>n;
vector<int> arr;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr.push_back(a);
}

int p_idx = pivotDetection(arr);
// cout<<"p:"<<p_idx;
int t;
cin>>t;
while(t--){

    int key;
    cin>>key;
    if(p_idx == n-1){ // not rotated simple bsearch 
        cout<<bsearch(arr,0,n-1,key)<<endl;
    }
    else if(arr[0]<=key && key<=arr[p_idx]){
        cout<<bsearch(arr,0,p_idx,key)<<endl;
    }
    else{
        cout<<bsearch(arr,p_idx+1,n-1,key);
    }

}


}

