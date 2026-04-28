class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<int,int>evenfreq;
        unordered_map<int,int>oddfreq;
        for(int i=0;i<s1.length();i++){
             if(i%2==0){
                evenfreq[s1[i]]++;
             }
             else{
                oddfreq[s1[i]]++;
             }
        }
        for(int i=0;i<s2.length();i++){
             if(i%2==0){
                if(evenfreq[s2[i]]>0)
                evenfreq[s2[i]]--;
                else
                return false;
             }
             else{
                if(oddfreq[s2[i]]>0){
                    oddfreq[s2[i]]--;
                }
                else
                return false;
             }
        }
        return true;
    }
};