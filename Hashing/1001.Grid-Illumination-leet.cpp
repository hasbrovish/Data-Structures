/*
https://leetcode.com/problems/grid-illumination/description/
*/

/*
Mistake done :
1. making of grid every time was an costly operation
2. tracking the jd bulbs
which was not reuired to b done 
3. also in case if the lamp is repeatie then insert that lamp on inly once in
   the array
4. use set or map for to maintain unqiie lamps 
5. see keys are ot reuired to be maintained for the lamp so we can go for sing
   set her
6. When i was using array to store frequencies of row , col and diagonal memory
   limite excced was coming , as 0<n<10^9 and contraint to be fi in array was N
   ~ 10^9 which cann't be accomodate in array hence required to use
   unordered_map crux : see eventually blb will glw only if it is lighten by
   some lamp so while checking the adj 9 blubs if any lamp is alredy turned on
   then need to focus to turn off that bulb and decrasing the count and removing
   from the lamp on array 
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rowArr, colArr, majDia,
            minDia;
        vector<int> res;
        set<pair<int, int>> lampOn;
        for (int i = 0; i < lamps.size(); i++) {
            int x = lamps[i][0], y = lamps[i][1];
            if (lampOn.find({x, y}) == lampOn.end()) {
                lampOn.insert({x, y});
                rowArr[x]++;
                colArr[y]++;
                majDia[x - y ]++;
                minDia[x + y]++;
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            if (rowArr[x] == 0 && colArr[y] == 0 &&
                majDia[x - y] == 0 && minDia[x + y] == 0)
                res.push_back(0);
            else {
                res.push_back(1);
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            lampOn.find({nx, ny}) != lampOn.end()) {
                            cout << nx << " " << ny << endl;
                            lampOn.erase({nx, ny});
                            rowArr[nx]--;
                            colArr[ny]--;
                            majDia[nx - ny]--;
                            minDia[nx + ny]--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){

    int n;
    cin>>n;
    
    int len_lp,len_q;
    cin>>len_lp;
    cin>>len_q;
    vector<vector<int>>lamps(len_lp,vector<int>(2)),queries(len_q,vector<int>(2));
    cout<<"input for lamps";
    for(int i=0;i<len_lp;i++){
        cin>>lamps[i][0]>> lamps[i][1];
    }
    cout<<"input for queries";
    for(int i=0;i<len_q;i++){
        cin>>queries[i][0]>> queries[i][1];
    }
    Solution s;
    vector<int> res = s.gridIllumination(n,lamps,queries);
    for(auto i : res) cout<<i<<" ";
}