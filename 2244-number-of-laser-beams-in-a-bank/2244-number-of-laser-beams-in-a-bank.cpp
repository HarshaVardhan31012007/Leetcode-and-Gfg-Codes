class Solution {
public:
    bool check(string &k){
        for(int i=0;i<k.length();i++){
            if(k[i]=='1')
            return true;
        }
        return false;
    }
    int find(string &p){
        int count=0;
        for(int i=0;i<p.length();i++){
            if(p[i]=='1')
            count++;
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int count=0;
        int i=0;int j=1;
        while(j<bank.size()){
            bool a=check(bank[i]);
            bool b=check(bank[j]);
            if(a&&b){
               count+=find(bank[i])*find(bank[j]);
               i=j;
               j++;
            }
            else if(!a&&!b){
                i=j+1;
                j=j+2;
            }
            else if(!a){
                i++;
                if(i==j) j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};