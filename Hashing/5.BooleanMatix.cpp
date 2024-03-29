/*
Transform Boolean Matrix
markAsDonemarkForRevisionmarkForLater
Given a boolean matrix of size R x C where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.

Input Format

The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains two integer R and C, number of rows and number of columns of matrices respectively.
The next R lines each contain C integers separated by spaces describing rows of matrix (each element of the matrix is either 0 or 1).
Output Format

Print the modified matrix.
Input:

2
2 2
1 0
0 0
4 3
1 0 0
1 0 0
1 0 0
0 0 0
Output:

1 1
1 0
1 1 1
1 1 1
1 1 1
1 0 0
Explanation:

Testcase1: Only cell that has 1 is at (0,0) so all cells in row 0 are modified to 1 and all cells in column 0 are modified to 1.
Testcase2: The position of cells that have 1 in the original matrix are (0,0), (1,0) and (2,0). Therefore, all cells in row 0,1,2 are and column 0 are modified to 1.
Constraints:

1 ≤ T ≤ 10
1 ≤ N,M ≤ 10^3
0 ≤ MATRIX[i][j] ≤ 1
Example
Input
2
2 2
1 0
0 0
4 3
1 0 0
1 0 0
1 0 0
0 0 0
Output
1 1
1 0
1 1 1
1 1 1
1 1 1
1 0 0
*/
/*
the code was giving WA on all testcase ,
 then in intialised rowArr and colArr to fix the problem

*/

#include <iostream>
#include<vector>
using namespace std;
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        
        vector<int> rowArr(m,0);
        vector<int> colArr(n,0);
        vector<vector<int>> mat(m,vector<int>(n,0));
        vector<vector<int>> resMat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                
                if(mat[i][j]==1){
                   // resMat[i][j]=1;
                    rowArr[i]=1;
                    colArr[j]=1;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowArr[i]==1 || colArr[j]==1){
                    resMat[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<resMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}