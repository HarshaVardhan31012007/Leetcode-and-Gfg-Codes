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




class Solution {
public:
    string ans;
    void solve(string &target,int freq[26],int i,string temp){
        if(i>=target.size()) {
            if(temp>target){
                if(ans=="")
                ans=temp;
                else
                ans=min(ans,temp);
            }
            return;
        }
        if(freq[target[i]-'a']>0){
             freq[target[i]-'a']--;
             solve(target,freq,i+1,temp+target[i]);
             freq[target[i]-'a']++;
        }
        for(int j=target[i]-'a'+1;j<26;j++){
            if(freq[j]>0){
                freq[j]--;
                string temp1=temp;
                char ch=j+'a';
                temp1+=ch;
                for(int k=0;k<26;k++){
                    int count=freq[k];
                    while(count--){
                        char ch=k+'a';
                        temp1+=ch;
                    }
                }
                if(ans=="")
                ans=temp1;
                else
                ans=min(ans,temp1);
                freq[j]++;
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        int freq[26]={0};
        for(auto &ch:s)
        freq[ch-'a']++;
        string temp="";
        ans="";
        solve(target,freq,0,temp);
        return ans;
    }
};