#include <iostream>
#include<stack>
using namespace std;

void pushBottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    pushBottom(st,x);
    st.push(y);
}
void reverseStack(stack<int> &st){
    
    if(st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    cout<<x<<" ";
    reverseStack(st);
    pushBottom(st, x);
    
}


int main() {

    stack<int> st;
    int n ;
    cin>>n;
    for(int i=0;i<n;i++){
        int a ;
        cin>>a;
        st.push(a);
    }// your code goes here
     reverseStack(st);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    return 0;
}