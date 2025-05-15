class Solution {
public:
    // int minTimeToType(string word) {
    //     char ch='a';
    //     int count=0;
    //     for(int i=0;i<word.length();i++){
    //          if(word[i]==ch)
    //          count++;
    //          else{
    //             int mini=min((word[i]-ch+26)%26,(ch-word[i]+26)%26);
    //             count+=mini+1;
    //             ch=word[i];
    //          }
    //     }
    //     return count;
    // }


    int minTimeToType(string word) {
        int n=word.length();
        int count=n;
        int a=abs(word[0]-'a');
        count+=min(a,26-a);
        for(int i=1;i<n;i++){
                a=abs(word[i]-word[i-1]);
                count+=min(a,26-a);
        }
        return count;
    }
};