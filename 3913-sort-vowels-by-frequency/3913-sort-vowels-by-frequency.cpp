class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    int position(char ch){
        if(ch=='a') return 0;
        else if(ch=='e') return 1;
        else if(ch=='i') return 2;
        else if(ch=='o') return 3;
        return 4;
    }
    char get(int pos){
        if(pos==0) return 'a';
        else if(pos==1) return 'e';
        else if(pos==2) return 'i';
        else if(pos==3) return 'o';
        return 'u';
    }
    string sortVowels(string s) {
        vector<pair<int,int>>v(5,{0,0});
        unordered_map<int,int>mpp;
        vector<int>positions;
        for(int i=0;i<s.length();i++){
           if(isVowel(s[i])){
               int pos=position(s[i]);
               if(v[pos].first==0){
                 v[pos].first=1;
                 v[pos].second=i;
                 mpp[i]=pos;
               }
               else{
                v[pos].first++;
               }
               positions.push_back(i);
           }
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second<b.second;
        });
        int j=0;
        for(int i=0;i<5;i++){
            if(v[i].first!=0){
                char ch=get(mpp[v[i].second]);
                while(v[i].first--){
                    s[positions[j++]]=ch;
                }
            }
        }
        return s;
    }
};