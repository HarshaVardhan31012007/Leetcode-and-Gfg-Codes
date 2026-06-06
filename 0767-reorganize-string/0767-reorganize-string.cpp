class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        int arr[26]={0};
        int maxi=INT_MIN;char ch=0;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
            if(maxi<arr[s[i]-'a']){
                maxi=arr[s[i]-'a'];
                ch=s[i];
            }
        }
        if(maxi>ceil(n/2.0)) return "";
        int i=0;
        while(arr[ch-'a']>0){
            s[i]=ch;
            arr[ch-'a']--;
            i+=2;
        }
        if(i>=n) i=1;
        for(int j=0;j<26;j++){
            while(arr[j]>0){
                s[i]=(j+'a');
                i+=2;
                if(i>=n) i=1;
                arr[j]--;
            }
        }
        return s;
    }
};