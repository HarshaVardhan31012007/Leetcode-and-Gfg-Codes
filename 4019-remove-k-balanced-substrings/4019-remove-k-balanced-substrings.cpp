class Solution {
public:
    string removeSubstring(string s, int k) {

        //TLE//O(m*n*m/n)//O(m*m)
        // string temp="";
        // for(int i=0;i<k;i++){
        //      temp+='(';
        // }
        // for(int i=0;i<k;i++){
        //      temp+=')';
        // }
        // int idx=s.find(temp);
        // while(idx!=string::npos){
        //     s.erase(idx,2*k);
        //     idx=s.find(temp);
        // }
        // return s;


        //  string temp="";
        //  for(int i=0;i<k;i++){
        //      temp+='(';
        //  }
        //  for(int i=0;i<k;i++){
        //      temp+=')';
        //  }
        // string str="";
        // //O(m*n)//s.compare(idx,len,compare_string) saves space
        // for(int i=0;i<s.length();i++){
        //     str+=s[i];
        //     while(str.length()>=2*k&&!str.compare(str.length()-2*k,2*k,temp)){
        //         int count=2*k;
        //         while(count--)
        //         str.pop_back();
        //     }
        // }
        // return str;



        stack<pair<char,int>>st;
        string ans="";
        for(auto &ch:s){
              if(!st.empty()&&st.top().first==ch)
              st.top().second++;
              else
              st.push({ch,1});
              if(st.size()>=2){
                auto top2=st.top();st.pop();
                auto& top1=st.top();
                if(top1.first=='('&&top2.first==')'&&top1.second>=k&&top2.second>=k){
                    top1.second-=k;
                    top2.second-=k;
                    if(!top1.second)
                    st.pop();
                }
                else
                st.push(top2);
              }
        }
        while(!st.empty()){
            while(st.top().second--)
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};