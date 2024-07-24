class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s){
            if(i=='{' || i=='(' || i=='['){
                st.push(i);
            }else{
                //char top = st.top();
                if(st.empty() || (i=='}' && st.top()!='{') 
                    || (i==']' && st.top()!='[')
                    || (i==')' && st.top()!='(') )
                    return false;
                st.pop();     
            }
        }   
    return st.empty();
    
    //below approach O(n^2) but o(1) additional space 
    // while(true){
    //     int pos;
    //     if((pos=s.find("()"))!=string::npos)
    //         {
    //         s.erase(pos,2);
    //     }else if((pos=s.find("[]"))!=string::npos){
    //         s.erase(pos,2);
    //     }else if((pos=s.find("{}"))!=string::npos){
    //         s.erase(pos,2);
    //     }else{
    //         return s.size()==0;
    //     }
    // }

    //O(n) time and o(1) space
    // for()
    }
};