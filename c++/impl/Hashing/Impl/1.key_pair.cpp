/*
    Key Pair
    markAsDonemarkForRevisionmarkForLater
    Given an array arr of N integers, and an integer K, Determine whether or not there exist two elements in arr whose sum is exactly K.

    Input Format

    The first line contains two spaced integers N and K denoting the size of the array and the target sum respectively.
    The second line contains N space-separated integers denoting the elements of the array.
    Output Format

    Print "Yes" if there exist two elements in arr whose sum is exactly K otherwise print "No".
    Input 1:

    6 16
    1 4 45 6 10 8
    Output 1:

    Yes
    Explanation:

    arr[3] + arr[4] = 6 + 10 = 16
    Constraints:

    1 ≤ N ≤ 10^5
    1 ≤ K ≤ 2*10^5
    1 ≤ arr[i] ≤ 10^5
    Example
    Input
    6 16
    1 4 45 6 10 8
    Output
    Yes
*/

#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
    // your code goes here
    int n, k;
    cin>>n>>k;
    string f = "No";
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        if(m.find(k-a[i])!=m.end()) 
        {
            f = "Yes";
            break;
            
        }
        else
            m.insert({a[i],0});
    }
    
    cout<<f;
    return 0;
}
