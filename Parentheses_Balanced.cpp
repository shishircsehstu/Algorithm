class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int len = s.size();
        
        for(int i=0;i<len;i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top()=='(' && s[i]==')'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
        /*
         st size represent how many character are not balance.
         if size>0 that means string is not balanced
         */
    }
};
