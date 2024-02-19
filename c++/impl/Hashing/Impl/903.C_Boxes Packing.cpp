/*
https://codeforces.com/contest/903/problem/C
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#define loop(n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int n;
cin>>n;
vector<int> a(n);
map<int,int> m;
int count = 0;
loop(n){
    cin>>a[i];
    m[a[i]]++;
    count =max(count,m[a[i]]);
    //cout<<count<<" ";
}
cout<<count;

}
