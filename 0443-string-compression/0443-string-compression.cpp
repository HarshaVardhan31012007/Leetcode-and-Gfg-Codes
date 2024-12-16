class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        if(chars.size()==1){
            return 1;
        }
        int count=1;
        int ans=0;
        for(int i=1;i<chars.size();i++){
           if(chars[i-1]==chars[i]){
           count++;
           if(i==chars.size()-1&&count>1){
             s.push_back(chars[i]);
             ans++;
             string n=to_string(count);
             for(char each:n){
             s.push_back(each);
             ans++;
             }
             
           }
           if(i==chars.size()-1&&count==1){
            s.push_back(chars[i]);
            ans++;
           }
     
           }
           else{
             if(count==1){
             s.push_back(chars[i-1]);
             ans++;
               }
             else {
                s.push_back(chars[i-1]);
                ans++;
                string n=to_string(count);
                for(char each:n){
                s.push_back(each);
                ans++;
                }
             count=1;
             }
            if(i==chars.size()-1){
             s.push_back(chars[i]);
             ans++;
            }

        }
        }
        for(int i=0;i<s.length();i++){
            chars[i]=s[i];
        }
        return ans;

        //method 2
        // int i=0;
        // int ans=0;
        // int n=chars.size();
        // while(i<n){//tc: big of n//sc: big of 1
        //     int j=i+1;
        //     while(j<n&&chars[i]==chars[j]){
        //         j++;
        //     }
        //     int count=j-i;
        //     chars[ans++]=chars[j-1];
        //     if(count>1){
        //         string n=to_string(count);
        //         for(char ch:n){
        //             char[ans++]=ch;
        //         }

        //     }
        //     i=j;
        // }
        //  for(int i=0;i<s.length();i++){
        //     chars[i]=s[i];
        // }
        // return ans;
    }
};