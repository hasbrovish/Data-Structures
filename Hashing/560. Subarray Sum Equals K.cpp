#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m.insert({0, 1});
        int count = 0, psum = 0;
        for (int i = 0; i < nums.size(); i++) {
            psum += nums[i];
            if (m.find(psum - k) != m.end()) {
                count += m[psum - k];
            }
            m[psum]++;
        }
        return count;
    }
};

int main(){
    Solution s ;
    cout<<s.subarraySum({1,2,3,4},0);
}