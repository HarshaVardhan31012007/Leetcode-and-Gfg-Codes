class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mpp;
        int count=0;
        for(auto &each:word)
        mpp[each]++;
        for(auto &each:mpp){
            if(islower(each.first)){
                if(mpp[each.first]>=1&&mpp[(char)((each.first-'a')+'A')]>=1){
                   count++;
                   mpp[each.first]=0;
                   mpp[(each.first-'a')+'A']=0;
                }
            }
        }
        return count;
    }
};