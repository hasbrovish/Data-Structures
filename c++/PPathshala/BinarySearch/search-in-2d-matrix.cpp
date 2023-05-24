#include<bits/stdc++.h>
using namespace std;

int findRow(vector<vector<int>> &arr,int key){
    
    int m = arr.size();
    int l=0,h=m-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid][0]<=key && ((mid==m-1) || (arr[mid+1][0]>key))){
            return mid;
        }
        else if(arr[mid][0]<=key)
            l=mid+1;
        else 
            h=mid-1;
    }

}

bool findkey(vector<int> v,int key){
    int n=v.size();
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(v[m]==key) return true;
        else if(v[m]>key) h=m-1;
        else l=m+1;
    }
return false;
}



int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr;
    for(int i=0;i<m;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int v;
            cin>>v;
            temp.push_back(v);
        }
        arr.push_back(temp);
    }
    int t;
    cin>>t;
    while(t--){
    int key;
    cin>>key;
    int row = findRow(arr,key);
    // cout<<row<<" "<<endl;
    if(findkey(arr[row],key))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;

    }
}