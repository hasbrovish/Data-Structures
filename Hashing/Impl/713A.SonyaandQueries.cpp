// https://codeforces.com/problemset/problem/713/A

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string getBin(long long int v){
    string num = "";
    while(v!=0){
        //cout<<v<<endl;
        int r = (v%10)%2;
        //cout<<"r"<<r<<endl;
        num = to_string(r) + num;
        //cout<<"num"<<num<<endl;
        v = v/10;
    }
   // cout<<num;
    return num;
}
int main(){
    int q;
    cin>>q;
    unordered_map<long long int,int> m;
    while(q--){
        char c;
        cin>>c;
        long long int v;
        string s;
        if(c=='+') {
            cin>>v;
            m[stoll(getBin(v))]++;
        } 
        else if(c=='-'){
             cin>>v;
            m[stoll(getBin(v))]--;
        }
        else if(c=='?'){
             cin>>v;
            cout<<m[v]<<endl;
        }
    }
}