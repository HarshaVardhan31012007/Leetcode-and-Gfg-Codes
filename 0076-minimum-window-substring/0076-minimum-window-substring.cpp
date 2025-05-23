class Solution {
public:
    string minWindow(string s, string t) {
    // if(s.length()<t.length()) return "";
    //    int start=0;
    //    int end=0;
    //    int len=INT_MAX;
    //    int ansIdx=0;int count=0;
    //    unordered_map<char,int>freq1;
    //    unordered_map<char,int>freq2;
    //    for(auto &each:t)
    //    freq2[each]++;
    //    while(end<s.length()){
    //     freq1[s[end]]++;
    //     if(freq1[s[end]]<=freq2[s[end]])
    //     count++;
    //     while(count==t.length()){       
    //                     if(end-start+1<len){
    //             len=end-start+1;
    //             ansIdx=start;
    //         }
    //         if(freq1[s[start]]<=freq2[s[start]]) count--;
    //          freq1[s[start]]--;
    //          start++;
    //     }
    //     end++;
    //    }
    //    return len==INT_MAX?"":s.substr(ansIdx,len);


    if(s.length()<t.length()) return "";
       int start=0;
       int end=0;
       int len=INT_MAX;
       int ansIdx=0;int count=t.length();
       unordered_map<char,int>freq;
       for(auto &each:t)
       freq[each]++;
       while(end<s.length()){
        if(freq[s[end]]>0) count--;
        freq[s[end]]--;
        while(count==0){       
            if(end-start+1<len){
            len=end-start+1;
            ansIdx=start;
            }
            freq[s[start]]++;
            if(freq[s[start]]>0) count++;
            start++;
        }
        end++;
       }
       return len==INT_MAX?"":s.substr(ansIdx,len);
    }
};