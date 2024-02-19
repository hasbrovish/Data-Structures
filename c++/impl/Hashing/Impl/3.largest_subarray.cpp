/*
    
Largest Subarray
markAsDonemarkForRevisionmarkForLater
Given an array arr of positive and negative numbers. The task is to compute the length of the largest subarray with sum 0. If no subarray of sum 0 is present then output 0.

Input Format

The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of the array.
The second line of each case contains N space-separated integers denoting the elements of the array.
Output Format

Print the length of the largest subarray with sum 0.
Input:

2
8
15 -2 2 -8 1 7 10 23
5
4 2 4 1 6
Output:

5
0
Explanation:

Testcase1: The largest subarray with sum 0 will be -2 2 -8 1 7.
Testcase2: There is no subarray with sum 0.
Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
-10^5 ≤ arr[i] ≤ 10^5
Example
Input
2
8
15 -2 2 -8 1 7 10 23
5
4 2 4 1 6
Output
5
0
*/
/*
    for Largest Subarray with sum K see changes in comment of the code
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
        int len = 0;
        Loop(n){
            cin>>a[i];
        }
        
        unordered_map<int,int> m;
        int psum = 0;
        m.insert({0,-1}); //logicaly think will able to figure out why
        Loop(n){
            psum += a[i];
            if(m.find(psum)!=m.end()){ //psum-k
                len = max(len , i - m[psum]); //psum-k
            } 
            else
                m[psum] = i;
        }
        cout<<len<<endl;
    }
    return 0;
}