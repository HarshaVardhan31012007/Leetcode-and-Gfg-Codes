class Solution {
public:
    // iterative 



    //string decodeString(string s) {
        //first three approaches are like on string concatenation first  temp=temp+a
        //second is temp.append(a) and third is temp=a+temp 

        // stack<string>st;
        // for(int i=0;i<s.length();i++){
        //   if(s[i]==']'){
        //         string temp="";
        //         while(st.top()[0]!='['){
        //             temp+=st.top();
        //             st.pop();
        //         }
        //         st.pop();
        //         string num="";
        //         while(!st.empty()&&isdigit(st.top()[0])){
        //             num=st.top()+num;
        //             st.pop();
        //         }
        //         int n=stoi(num);
        //         string decode="";
        //         while(n--){
        //             decode=decode+temp;
        //         }
        //         st.push(decode);
        //   }
        //   else{
        //      string temp(1,s[i]);
        //      st.push(temp);
        //   }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans=ans+st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;




        //  stack<string>st;
        // for(int i=0;i<s.length();i++){
        //   if(s[i]==']'){
        //         string temp="";
        //         while(st.top()[0]!='['){
        //             temp.append(st.top());
        //             st.pop();
        //         }
        //         st.pop();
        //         string num="";
        //         while(!st.empty()&&isdigit(st.top()[0])){
        //             num=st.top()+num;
        //             st.pop();
        //         }
        //         int n=stoi(num);
        //         string decode="";
        //         while(n--){
        //             decode=decode+temp;
        //         }
        //         st.push(decode);
        //   }
        //   else{
        //      string temp(1,s[i]);
        //      st.push(temp);
        //   }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans=ans.append(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;




        // stack<string>st;
        // for(int i=0;i<s.length();i++){
        //   if(s[i]==']'){
        //         string temp="";
        //         while(st.top()[0]!='['){
        //             temp=st.top()+temp;
        //             st.pop();
        //         }
        //         st.pop();
        //         string num="";
        //         while(!st.empty()&&isdigit(st.top()[0])){
        //             num=st.top()+num;
        //             st.pop();
        //         }
        //         int n=stoi(num);
        //         string decode="";
        //         while(n--){
        //             decode=decode+temp;
        //         }
        //         st.push(decode);
        //   }
        //   else{
        //      string temp(1,s[i]);
        //      st.push(temp);
        //   }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans=st.top()+ans;
        //     st.pop();
        // }
        // return ans;



        
       //this approach (skipping [) is not correct because 4[2[a]] int his case 
       // if we skip [ this, a have num 42 but it has 2 only

        // stack<string>st;
        // for(int i=0;i<s.length();i++){
        //   if(s[i]==']'){
        //         string temp="";
        //         while(!isdigit(st.top()[0])){
        //             temp+=st.top();
        //             st.pop();
        //         }
        //         string num="";
        //         while(!st.empty()&&isdigit(st.top()[0])){
        //             num=st.top()+num;
        //             st.pop();
        //         }
        //         int n=stoi(num);
        //         string decode="";
        //         while(n--){
        //             decode=decode+temp;
        //         }
        //         st.push(decode);
        //   }
        //   else if(s[i]!='['){
        //      string temp(1,s[i]);
        //      st.push(temp);
        //   }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans=ans+st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
    //}



    //recursive

    string helper(string &s,int &i){
         
         int num=0;
         string ans="";
         for(;i<s.length();i++){
            char ch=s[i];
             if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
             }
             else if(isalpha(s[i])){
                ans+=s[i];
             }
             else if(s[i]=='['){
                i++;
                string temp=helper(s,i);
                for(int i=0;i<num;i++){
                    ans+=temp;
                }
                num=0;
             }
             if(ch==']') break;
         }
         return ans;
    }
    string decodeString(string s) {
         int i=0;
         return helper(s,i);
    }
};