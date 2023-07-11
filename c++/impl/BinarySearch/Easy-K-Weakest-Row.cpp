#include<bits/stdc++.h>
using namespace std;
int getOneCount(int i,vector<vector<int>> &mat){

        int l =0, h = mat[i].size()-1;

        while(l<=h){
			
            int mid = (l+h)/2;
		
            if(mat[i][mid]==1){
                    l=mid+1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
    void kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> sum(mat.size());
        multimap<int,int> mp;
        int size = mat.size();
        for(int i=0;i< size ;i++){
         // cout<<getOneCount(i,mat)<<" "<<i<<endl;
            mp.insert(make_pair(getOneCount(i,mat),i));
        }
        vector<int> res;
        for(auto i : mp){
            if(k==0) break;
            cout<<i.second<<" ";
            k--;
            }
    }
int main(){
	int k,n,m;
	cin>>n>>m;
	vector<vector<int>> mat;
	
	for(int i=0;i<n;i++){
        vector<int> temp ;
		for(int j =0;j<m;j++){
            int a;
            cin>>a;
			temp.push_back(a);
		}
        mat.push_back(temp);
	}	
kWeakestRows(mat,n);
}