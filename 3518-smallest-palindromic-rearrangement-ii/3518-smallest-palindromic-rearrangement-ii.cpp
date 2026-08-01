class Solution {
public:
    string smallestPalindrome(string s, int k1) {
        char midc=0;
        int n=s.length();
        if(n&1){
            midc=s[n/2];
        }
        int mid=n/2;
        vector<int>freq(26,0);
        for(int i=0;i<mid;i++)
        freq[s[i]-'a']++;
        string half;
        for(int i=0;i<mid;i++){
            bool flag=false;
            for(int j=0;j<26;j++){
                if(freq[j]==0) continue;
                freq[j]--;
                long long ways=1;
                int pos=mid-i-1;
                for(int k=0;k<26;k++){
                    if(freq[k]==0) continue;
                    int r1=min(freq[k],pos-freq[k]);
                    for(int r=1;r<=r1;r++){
                        ways=ways*(pos-r1+r)/r;
                        if(ways>=k1) break;
                    }
                    if(ways>=k1){
                        break;
                    }
                    pos-=freq[k];
                }
                if(ways>=k1){
                    flag=true;
                    half.push_back(j+'a');
                    break;
                }
                k1-=ways;
                freq[j]++;
            }
            if(!flag) return "";
        }
        string temp=half;
        reverse(half.begin(),half.end());
        if(midc!=0) temp+=midc;
        temp+=half;
        return temp;
    }
};