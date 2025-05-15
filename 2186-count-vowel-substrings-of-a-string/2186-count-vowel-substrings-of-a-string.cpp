class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.length();int count=0;
        for(int k=0;k<n;k++){
            int a=0;int e=0;int i=0;int o=0;int u=0;
            for(int j=k;j<n;j++){
                if(word[j]=='a')
                a=1;
                else if(word[j]=='e')
                e=1;
                else if(word[j]=='i')
                i=1;
                else if(word[j]=='o')
                o=1;
                else if(word[j]=='u')
                u=1;
                else
                break;
               if(a==1&&e==1&&i==1&&o==1&&u==1)
               count++;
            }
        }
        return count;
    }
};