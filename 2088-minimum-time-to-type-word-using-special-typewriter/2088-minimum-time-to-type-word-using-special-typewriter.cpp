class Solution {
public:
    int minTimeToType(string word) {
        char ch='a';
        int count=0;
        for(int i=0;i<word.length();i++){
             if(word[i]==ch)
             count++;
             else{
                int mini=min((word[i]-ch+26)%26,(ch-word[i]+26)%26);
                count+=mini+1;
                ch=word[i];
             }
        }
        return count;
    }
};