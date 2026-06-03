class Solution {
public:
    string frequencySort(string s) {
        int freq[256]={0};
        for(auto &each:s)
        freq[each]++;
        sort(s.begin(),s.end(),[&](char a,char b){
            if(freq[a]!=freq[b])
            return freq[a]>freq[b];
            else
            return a>b;
        });
        return s;
    }
};