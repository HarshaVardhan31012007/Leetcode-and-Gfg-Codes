class Solution {
  public:
    int countMinReversals(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(s[i]=='}'){
                    s[i]='{';
                    count++;
                }
                st.push(s[i]);
            }
            else{
                if(s[i]=='}'){
                   st.pop();
                }
                else
                st.push(s[i]);
            }
        }
        if(st.size()&1)
        return -1;
        return count+st.size()/2;
    }
};