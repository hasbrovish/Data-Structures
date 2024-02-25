/*
   Given an array arr[] of size N, the task is to check whether the array consists of consecutive numbers or not.

Input Format

The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the size of the array.
The second line of each case contains N space-separated integers denoting the elements of the array.
Output Format

Print "Yes" if the array consists of consecutive numbers otherwise "No".
Input:

2
5
5 4 3 2 1
3
1 1 1
Output:

Yes
No
Explanation:

Testcase1: All are consecutive elements, according to this order 1,2,3,4 and 5.
Testcase2: As (1,1) are not consecutive numbers hence, the output is "No".
Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
-10^5 ≤ arr[i] ≤ 10^5
Example
Input
2
5
5 4 3 2 1
3
1 1 1
Output
Yes
No
*/

#include<iostream>
#include<unordered_map>
#include<climits>
#include<string>

using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        int a[n];
        int mini = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
            mini = min(mini,a[i]);
        }
        string flag = "Yes";
        for(int i=mini ; i<mini+n;i++){
            if(m[i]==0) {
                flag = "No";
                break;
            }
        }
        cout<<flag<<endl;
    }
}