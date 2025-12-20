class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // int len=strs[0].length();
        // int count=0;
        // for(int i=0;i<len;i++){
        //     int j=1;
        //     for(;j<strs.size();j++){
        //          if(strs[j][i]<strs[j-1][i])
        //          break;
        //     }
        //     if(j==strs.size())
        //     count++;
        // }
        // return len-count;



        int len=strs[0].length();
        int count=0;
        for(int i=0;i<len;i++){
            for(int j=1;j<strs.size();j++){
                 if(strs[j][i]<strs[j-1][i]){
                    count++;
                    break;
                 }
            }
        }
        return count;
    }
};