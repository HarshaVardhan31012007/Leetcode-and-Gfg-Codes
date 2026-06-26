class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string,int>>st;
        st.push(map<string,int>());
        int n=formula.size();
        int i=0;
        while(i<n){
            if(isalpha(formula[i])&&isupper(formula[i])){
                string temp="";
                temp+=formula[i++];
                int count=0;
                while(i<n&&isalpha(formula[i])&&islower(formula[i])){
                    temp+=formula[i++];
                }
                while(i<n&&isdigit(formula[i])){
                    count=count*10+(formula[i++]-'0');
                }
                if(count==0) count=1;
                auto &mpp=st.top();
                mpp[temp]+=count;
            }
            else if(formula[i]=='('){
                st.push(map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                auto mpp=st.top();
                st.pop();
                i++;
                int count=0;
                while(i<n&&isdigit(formula[i])){
                    count=count*10+(formula[i++]-'0');
                }
                if(count==0) count=1;
                auto &mpp1=st.top();
                for(auto &each:mpp){
                    mpp1[each.first]+=each.second*count;
                }
            }
        }
        string ans="";
        for(auto &each:st.top()){
            ans+=each.first;
            if(each.second>1)
            ans+=to_string(each.second);
        } 
        return ans;
    }
};