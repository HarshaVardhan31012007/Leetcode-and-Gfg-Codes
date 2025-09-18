class Solution {
public:
    // int minSwaps(string s) {
    //     stack<char>st;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='['){
    //             st.push(s[i]);
    //         }
    //         else{
    //             if(!st.empty()&&st.top()=='[')
    //             st.pop();
    //             else
    //             st.push(s[i]);
    //         }
    //     }
    //     // if(st.size()==0)
    //     // return 0;
    //     // if(st.size()==2)
    //     // return 1;
    //     return ceil(st.size()/4.0);
    // }



    int minSwaps(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty())
                st.pop();
                else
                count++;
            }
        }
        // if(st.size()==0)
        // return 0;
        // if(st.size()==2)
        // return 1;
        return ceil((count+st.size())/4.0);
    }
};