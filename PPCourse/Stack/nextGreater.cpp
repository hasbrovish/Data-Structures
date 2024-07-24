#include<iostream>
#include<vector>

using namespace std;

//Brute force 
int main(){
    vector<int> a ={1,4,50,6,70, 12 , 13, 80, 3 , 4, 5};
    int nge[a.size()];
    for(int i=0;i<a.size();i++){
        if(i==a.size()-1) {
            nge[a.size()-1] = -1;
            break;
        }
        else{
            int j;
            for(j=i+1;j<a.size();j++){
                if(a[j]>a[i]) {
                    nge[i] = a[j];
                    break;
                }
            }
            if(j==a.size()){
                nge[i]= -1;
            }
        }
    }
    for(int i: nge){
        cout<<i<<" ";
    }
}