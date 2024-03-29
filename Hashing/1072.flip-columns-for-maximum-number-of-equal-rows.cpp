
/*
https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/
*/

/*
Technique:
 1.A "Hash Key" is generated out of every row
 2.In matrix questions focus on what is required to be hashed to sovet he problem .
 3.Here every row an its negation is converted in to a Bit number using Bitset 4.Bit
    number is only choosen as a hash as to make a common pattern in rows ex:
    1101 and 0010 belong to a same pattern , and this common property can be
    satisfy by finding out the bit number fot both the rows as ~(1101) = 0010 ∴
    using bitset can save entire bit and we can check the maximun frequency out
    of all the bitsets

*/
class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> mp;
        long long int sum1, sum2;
        int ans=0,n =matrix[0].size();
        for (int i = 0; i < matrix.size(); i++) {
            bitset<300> bits1,bits2;
            for (int j = 0; j < matrix[0].size(); j++) {
                bits1[j] = matrix[i][j];
                bits2[j] = 1-matrix[i][j];
            }
            // if(sum1==sum2){
            //     mp[sum1]++;
            // }
            //else{
            mp[bits1]++;
            mp[bits2]++;
            //}
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            ans = max(ans, i->second);
        }
        return ans;
    }
};
