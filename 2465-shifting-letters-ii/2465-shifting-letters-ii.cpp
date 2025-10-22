class Solution {
public:
    // string shiftingLetters(string s, vector<vector<int>>& shifts) {
    //     int n=s.length();
    //     vector<long long int>v(n,0);
    //     for(auto &shift:shifts){
    //         int &s=shift[0];int e=shift[1]+1;// s is local variable
    //         if(shift[2]==1){
    //              v[s]=v[s]+1;
    //              if(e<n)
    //              v[e]=v[e]-1;
    //         }
    //         else{
    //              v[s]=v[s]-1;
    //              if(e<n)
    //              v[e]=v[e]+1;
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         v[i]+=i>0?v[i-1]:0;
    //         int curr=s[i]-'a';
    //         curr=(curr+v[i]%26+26)%26;
    //         s[i]=curr+'a';
    //     }
    //     return s;
    // }




    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<long long int>v(n,0);
        for(auto &shift:shifts){
            int st=shift[0];int e=shift[1]+1;
            if(shift[2]==1){
                 v[st]=(v[st]+1)%26;
                 if(e<n)
                 v[e]=(v[e]-1+26)%26;
            }
            else{
                 v[st]=(v[st]-1+26)%26;
                 if(e<n)
                 v[e]=(v[e]+1)%26;
            }
        }
        for(int i=0;i<n;i++){
            v[i]=(v[i]+(i>0?v[i-1]:0))%26;
            int curr=s[i]-'a';
            curr=(curr+v[i])%26;
            s[i]=curr+'a';
        }
        return s;
    }
};