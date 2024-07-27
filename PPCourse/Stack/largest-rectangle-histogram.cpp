// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    //previous smaller
    //next smaller
    //maximise the answer
    int n;
    void previousSmaller(vector<int> &prev,vector<int> &next, vector<int>  &heights){
        stack<int> st;
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            prev[st.top()] = -1;
            st.pop();
        }
        st.push(0);
        for(int i = 1;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            next[st.top()] = n;
            st.pop();
        }
    }

    void nextSmaller(vector<int> &next,vector<int>  &heights){
        stack<int> st;
        
    }

    int largestRectangleArea(vector<int> &heights) {
        int ans = INT_MIN;
        n = heights.size();
        vector<int> prev(n) , next(n);
        previousSmaller(prev,next,heights);
//        nextSmaller(next,heights);

        for(int i=0;i<n;i++){
            cout<<heights[i]<<" prev:"<< prev[i] <<" next:"<< next[i]<<endl;
            ans = max(ans , heights[i] * (next[i]-prev[i]-1));
        }
    return ans;
    }
};

Single Pass :
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;
        int prev , next;
        stack<int> st;
        int n = heights.size();
       // st.push(0);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                next = i;
                int h = heights[st.top()];
                st.pop();
                int w = st.empty()? i : (i-st.top()-1); 
                ans = max(ans, h*w);
            }
            st.push(i);
        }
        cout<<"after loop";
        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();
            int w = st.empty()? n : (n-st.top()-1); 
            ans = max(ans, h*w);
        }
    return ans;
    }
};