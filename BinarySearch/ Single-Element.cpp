#include<bits/stdc++.h>
using namespace std;

int singleElem(vector<int> arr,int n){

    int l=0,h=n-1;
    while(l<=h){

        int m=(l+h)/2;
        if(m==0) 
        {
            if(arr[0]!=arr[1]) return arr[0];
            l=m+1;
        }
        else if(m==n-1){
            if(arr[n-2]!=arr[n-1]) return arr[n-1];
            h=m-1;
        }
        else{
            if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]) return arr[m];
            int f,s;
            if(arr[m]==arr[m-1]) {
                f=m-1,s=m;  
            }
            else{
                f=m,s=m+1;
            }

            if(f%2==0) l=m+1;
            else h=m-1;

        }
    }

}

int main(){

int n;
cin>>n;
vector<int> arr;

for(int i=0;i<n;i++){
    int a; cin>>a;
    arr.push_back(a);
}

cout<<singleElem(arr,n);

}