class Solution {
  public:
    // int countMinReversals(string s) {
    //     if(s.size()&1) return -1;
    //     stack<char>st;
    //     int count=0;
    //     for(int i=0;i<s.length();i++){
    //         if(st.empty()){
    //             if(s[i]=='}'){
    //                 s[i]='{';
    //                 count++;
    //             }
    //             st.push(s[i]);
    //         }
    //         else{
    //             if(s[i]=='}'){
    //               st.pop();
    //             }
    //             else
    //             st.push(s[i]);
    //         }
    //     }
    //     // if(st.size()&1)
    //     // return -1;
    //     return count+st.size()/2;
    // }
    
    
    
    int countMinReversals(string s) {
        if(s.size()&1) return -1;
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
           if(s[i]=='{')
           st.push(s[i]);
           else{
               if(!st.empty()&&st.top()=='{')
               st.pop();
               else
               st.push('}');
           }
        }
        while(st.size()>1){
            int b=st.top();st.pop();
            int a=st.top();st.pop();
            if(a==b){
                count+=1;
            }
            else{
                count+=2;
            }
        }
        return count;
    }
};