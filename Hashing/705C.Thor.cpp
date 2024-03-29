#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> v; 
int main(){
    int a,q;
    cin>>a>>q;
    
    unordered_map<int,int> m;
    int unread=0;
    queue<int> unread_q;
    while(q--){
        int type,x,t;
        cin>>type>>x;
        int proccessed;
        switch (type)
        {
        case 1:
            v.push_back(x);
            m[x]++;
            unread++;
            cout<<unread<<endl;
            break;
        case 2:
            unread-=m[x];
            m[x]=0;
            cout<<unread<<endl;
            break;
        case 3:
             t=x;

            // if(unread<t) {
            //     cout<<"unread"<<unread<<endl;
            //     unread=0;
            // }
            // else{
            //     cout<<unread - t<<endl;
            //     unread-=t;
            // }
            for(int i=0;i<x && i<v.size();i++){
                if(m[v[i]]!=0){
                    unread--;
                    m[v[i]]--;
                }
            }
            cout<<unread<<endl;
            v.erase(v.begin(), v.begin() + min(x, (int)v.size()));
            break;
        }
    }


}