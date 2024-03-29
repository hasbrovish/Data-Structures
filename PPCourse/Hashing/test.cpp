#include<iostream>

using namespace std;
int gcd(int a,int b){
        if(a==0 && b==1) return 1;
        else if(a==1 && b==0) return 1;
        else if(b==0) return a;
        if(a>b) return gcd(b,a%b);
        else return gcd(a,b%a);
    }

int main(){
cout<<gcd(32,16);
cout<<" "<<gcd(4,40);

}