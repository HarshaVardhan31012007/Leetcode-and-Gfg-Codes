class Solution {
public:
    bool check(int arr[]){
        for(int i=0;i<26;i++){
            if(arr[i]!=0)
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
       int arr[26]={0};
       for(int i=0;i<s1.length();i++)
       arr[s1[i]-'a']++;
       int i=0;int j=s1.length()-1;
       for(int p=i;p<=j;p++)
       arr[s2[p]-'a']--;
       if(check(arr)) return true;
       j++;
       while(j<s2.length()){
         arr[s2[i++]-'a']++;
         arr[s2[j++]-'a']--;
         if(check(arr)) return true;
       }
       return false;
    }
};