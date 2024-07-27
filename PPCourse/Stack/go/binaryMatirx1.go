// https://www.hackerrank.com/contests/gl-bajaj-self-evaluation-contest/challenges/need-all-ones/problem
// code is faling to 3 testcase timeout is coming
// refer chandan
package main

import (
	"fmt"
)

type stack []int

func (s *stack) isEmpty() bool {

	return len(*s) == 0
}

func (s *stack) push(item int) {
	*s = append(*s, item)
}

func (s *stack) pop() {
	if s.isEmpty() {
		panic("Underflow")
	} else {
		*s = (*s)[:len(*s)-1]
	}
}

func (s *stack) top() int {
	return (*s)[len(*s)-1]
}

func Max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}
func main() {
	//Enter your code here. Read input from STDIN. Print output to STDOUT
	//Input m n and slice
	var m, n, ans int
	fmt.Scanln(&m, &n)
	arr := make([][]int, m)
	for i := 0; i < m; i++ {
		arr[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&arr[i][j])
		}
	}
	for j := 0; j < n; j++ {
		sum := 0
		for i := m - 1; i >= 0; i-- {
			if arr[i][j] == 0 {
				break
			} else {
				sum += arr[i][j]
			}
		}
		arr[m-1][j] = sum
	}

	// for i:=0;i<m;i++{
	//     for j:=0;j<n;j++{
	//         fmt.Printf("%d ", arr[i][j])
	//     }
	//     fmt.Printf("\n")
	// }

	height := arr[m-1]
	var st stack
	n = len(height)
	next := make([]int, n)
	prev := make([]int, n)
	st.push(n - 1)
	for i := n - 2; i >= 0; i-- {
		for !st.isEmpty() && height[i] < height[st.top()] {
			prev[st.top()] = i
			st.pop()
		}
		st.push(i)
	}
	for !st.isEmpty() {
		prev[st.top()] = -1
		st.pop()
	}
	st.push(0)
	for i := 1; i < n; i++ {
		for !st.isEmpty() && height[i] < height[st.top()] {
			next[st.top()] = i
			st.pop()
		}
		st.push(i)
	}
	for !st.isEmpty() {
		next[st.top()] = n
		st.pop()
	}

	for i := 0; i < n; i++ {
		ans = Max(ans, height[i]*(next[i]-prev[i]-1))
	}
	fmt.Println(ans)
}
