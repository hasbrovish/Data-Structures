#include <iostream>
#include <vector>
using namespace std;

int repeatElem(vector<int> v){
    int n = v.size();
    int l =0,h=n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(v[m]==m) h = m-1 ;
        else {
            if(v[m+1] == v[m]) return v[m];
            else l=m+1;
        }
    }

}

int main() {
    // your code goes here
    int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	cout<<repeatElem(v);
}