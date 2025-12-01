class Solution {
public:
    int maxDistinct(string s) {
        // set<char>st;
        // int ans=0;
        // for(auto &each:s){
        //     if(st.find(each)==st.end()){
        //         st.insert(each);
        //         ans++;
        //     }
        // }
        // return ans;


        set<char>st;
        for(auto &each:s){
            if(st.find(each)==st.end()){
                st.insert(each);
            }
        }
        return st.size();
    }
};