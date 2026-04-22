class Solution {
public:
    // vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    //     unordered_set<string>st(dictionary.begin(),dictionary.end());
    //     vector<string>ans;
    //     for(auto &each:queries){
    //         int n=each.length();
    //         bool found=false;
    //         for(int i=0;i<n;i++){
    //             char original=each[i];
    //             for(int j=0;j<26;j++){
    //                 each[i]=(j+'a');
    //                 if(st.count(each)){
    //                     found=true;
    //                     break;
    //                 }
    //                 for(int k=0;k<n;k++){
    //                     char original1=each[k];
    //                     for(int p=0;p<26;p++){
    //                         each[k]=(p+'a');
    //                         if(st.count(each)){
    //                             found=true;
    //                             break;
    //                         }
    //                     }
    //                     each[k]=original1;
    //                     if(found) break;
    //                 }
    //                 if(found) break;
    //             }
    //             each[i]=original;
    //             if(found) break;
    //         }
    //         if(found) ans.push_back(each);
    //     }
    //     return ans;
    // }




    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        vector<string>ans;
        for(auto &each:queries){
            bool found=false;
            for(auto &each1:dictionary){
                int c=0;
                for(int i=0;i<each.length();i++){
                    if(each[i]!=each1[i]){
                        c++;
                    }
                }
                if(c<=2){
                    found=true;
                    break;
                }
            }
            if(found)
            ans.push_back(each);
        }
        return ans;
    }
};