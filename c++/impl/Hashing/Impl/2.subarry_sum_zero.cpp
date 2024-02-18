/*

Subarray Sum Zero
markAsDonemarkForRevisionmarkForLater
Given an array arr of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Input Format

The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of the array.
The second line of each case contains N space-separated integers denoting the elements of the array.
Output Format

Print "Yes" if such subarray is present in the given array otherwise print "No".
Input:

2
5
4 2 -3 1 6
5
4 2 4 1 6
Output:

Yes
No
Explanation:

Testcase1: 2, -3, 1 is the subarray with sum 0.
Testcase2: There is no subarray with sum 0.
Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
-10^5 ≤ arr[i] ≤ 10^5
Example
Input
2
5
4 2 -3 1 6
5
4 2 4 1 6
Output
Yes
No

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


#define Loop(n) for(int i=0;i<n;i++)
using namespace std;
int main() {
    // your code goes here
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        string f = "No";
        Loop(n){
            cin>>a[i];
        }
        
        unordered_map<int,int> m;
        int psum = 0;
        m.insert({0,1});
        Loop(n){
            psum += a[i];
            if(m.find(psum)!=m.end()){
                f = "Yes";
                break;
            } 
            else
                m[psum] = 1;
        }
        cout<<f<<endl;
    }
    return 0;
}