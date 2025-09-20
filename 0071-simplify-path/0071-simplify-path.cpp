class Solution {
public:
    void buildans(stack<string>&st,string &ans){
        if(st.empty()) return;
        string temp=st.top();
        st.pop();
        buildans(st,ans);
        ans=ans+temp;
    }
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        while(i<path.length()){
             int j=i+1;
             while(j<path.length()&&path[j]!='/'){
                 j++;
             }
             string temp=path.substr(i,j-i);
             i=j;
             if(temp=="/."||temp=="/"){
                continue;
             }
             else if(temp!="/.."){
                st.push(temp);
             }
             else if(!st.empty()){
                st.pop();
             }
        }
        string ans=st.empty()?"/":"";
        buildans(st,ans);
        return ans;
    }
};