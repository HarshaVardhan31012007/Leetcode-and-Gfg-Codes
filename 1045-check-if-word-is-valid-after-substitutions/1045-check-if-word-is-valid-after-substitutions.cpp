class Solution {
public:
    bool isValid(string s) {

         // stack<string>st;
        // for(int i=0;i<s.length();i++){
        //      if(s[i]=='a') st.push(string(1,'a'));
        //      else if(s[i]=='b'){
        //         if(!st.empty()&&st.top()=="a"){
        //             st.pop();
        //             st.push("ab");
        //         }
        //         else{
        //             st.push(string(1,'b'));
        //         }
        //      }
        //      else{
        //      bool flag=0;
        //      if(!st.empty()&&s[i]=='c'&&st.top()=="ab"){
        //          flag=1;
        //          st.pop();
        //      }
        //      if(!flag) st.push(string(1,s[i]));
        //      }
        // }
        // return st.empty();



        //  stack<string>st;
        // for(int i=0;i<s.length();i++){
        //      if(s[i]=='a') st.push(string(1,'a'));
        //      else if(s[i]=='b'){
        //         if(!st.empty()&&st.top()=="a"){
        //             st.pop();
        //             st.push("ab");
        //         }
        //         else
        //         return false;
        //      }
        //      else{
        //      if(!st.empty()&&s[i]=='c'&&st.top()=="ab"){
        //          st.pop();
        //      }
        //      else
        //      return false;
        //      }
        // }
        // return st.empty();



        
       // if(s.size()==0) return true;
        if(s=="") return true;
       int idx=s.find("abc");
        if(idx!=string::npos){
            string l=s.substr(0,idx);
            string r=s.substr(idx+3);
            //don't do s=l+r and pass s
            //because l+r creates one copy
            //and s pass by value and again one copy
            return isValid(l+r);
            //only one copy
        }
        return false;
    }
};