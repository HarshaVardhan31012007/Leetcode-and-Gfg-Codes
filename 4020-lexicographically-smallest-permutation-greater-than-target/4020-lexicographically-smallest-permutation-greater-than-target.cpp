// class Solution {
// public:
//     string lexGreaterPermutation(string s, string target) {
//         sort(s.begin(),s.end());
//         if(s>target)
//             return s;
//         while(next_permutation(s.begin(),s.end())){
//             if(s>target)
//                 return s;
//         }
//         return "";
//     }
// };




// class Solution {
// public:
//     string ans;
//     void solve(string &target,int freq[26],int i,string temp){
//         if(i>=target.size()) {
//             return;
//         }
//         if(freq[target[i]-'a']>0){
//              freq[target[i]-'a']--;
//              solve(target,freq,i+1,temp+target[i]);
//              freq[target[i]-'a']++;
//              if(ans!="")
//              return;
//         }
//         for(int j=target[i]-'a'+1;j<26;j++){
//             if(freq[j]>0){
//                 freq[j]--;
//                 string temp1=temp;
//                 char ch=j+'a';
//                 temp1+=ch;
//                 for(int k=0;k<26;k++){
//                     int count=freq[k];
//                     while(count--){
//                         char ch=k+'a';
//                         temp1+=ch;
//                     }
//                 }
//                 ans=temp1;
//                 return;
//             }
//         }
//     }
//     string lexGreaterPermutation(string s, string target) {
//         int freq[26]={0};
//         sort(s.rbegin(),s.rend());
//         if(s<=target) return "";
//         for(auto &ch:s)
//         freq[ch-'a']++;
//         string temp="";
//         ans="";
//         solve(target,freq,0,temp);
//         return ans;
//     }
// };



class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<string>ans;
        multiset<char>st;
        for(auto &ch:s)
        st.insert(ch);
        string prefix="";
        for(int i=0;i<target.length();i++){
            auto it=st.upper_bound(target[i]);
            if(it!=st.end()){
                 string temp=prefix;
                 int val=*it;
                 temp.push_back(val);
                 st.erase(it);
                 for(auto &each:st)
                 temp.push_back(each);
                 ans.push_back(temp);
                 st.insert(val);
            }
            it=st.find(target[i]);
            if(it==st.end()) break;
            prefix+=target[i];
            st.erase(it);
        }
        if(ans.size()==0) return "";
        return *min_element(ans.begin(),ans.end());
    }
};