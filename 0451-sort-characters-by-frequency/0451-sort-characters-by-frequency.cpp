class Solution {
public:
    string frequencySort(string s) {
        // int freq[256]={0};
        // for(auto &each:s)
        // freq[each]++;
        // sort(s.begin(),s.end(),[&](char a,char b){
        //     if(freq[a]!=freq[b])
        //     return freq[a]>freq[b];
        //     else
        //     return a>b;
        // });
        // return s;

        pair<char,int>freq[256];
        for(int i=0;i<256;i++){
            freq[i]={i,0};
        }
        for(auto &each:s)
        freq[each].second++;
        sort(freq,freq+256,[&](pair<char,int>&p1,pair<char,int>&p2){
            if(p1.second!=p2.second) return p1.second>p2.second;
            else return p1.first>p2.first;
        });
        int i=0;
        for(int j=0;j<256;j++){
            if(freq[j].second!=0){
                char ch=freq[j].first;
                while(freq[j].second--){
                    s[i++]=ch;
                }
            }
        }
        return s;
    }
};