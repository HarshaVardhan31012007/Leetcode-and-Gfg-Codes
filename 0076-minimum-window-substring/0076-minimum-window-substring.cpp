class Solution {
public:
    // bool check(unordered_map<char,int>&mpp){
    //     for(auto &each:mpp){
    //         if(each.second>0) return false;
    //     }
    //     return true;
    // }
    // string minWindow(string s, string t) {
    //     if(s.length()<t.length()) return "";
    //     unordered_map<char,int>mpp;

    //     for(auto &each:t){
    //         mpp[each]++;
    //     }

    //     int i=0;
    //     int j=0;
    //     int n=s.length();
    //     int start=-1;int len=INT_MAX;
    //     while(j<n){
    //         if(mpp.count(s[j]))
    //         mpp[s[j]]--;
    //         while(check(mpp)){
    //             if((j-i+1)<len){
    //                 start=i;
    //                 len=(j-i+1);
    //             }
    //             if(mpp.count(s[i])) mpp[s[i]]++;
    //             i++;
    //         }
    //         j++;
    //     }
    //     if(start==-1) return "";
    //     return s.substr(start,len);
    // }




    
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int>mpp;

        for(auto &each:t){
            mpp[each]++;
        }

        int i=0;
        int j=0;
        int n=s.length();
        int start=-1;
        int len=INT_MAX;
        int count=t.length();

        while(j<n){
            if(mpp.count(s[j])){
               if(mpp[s[j]]>0) count--;
               mpp[s[j]]--;
            }
            while(count==0){
                if((j-i+1)<len){
                    start=i;
                    len=(j-i+1);
                }
                if(mpp.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0)
                    count++;
                }
                i++;
            }
            j++;
        }
        if(start==-1) return "";
        return s.substr(start,len);
    }
};