class Solution {
public:
    string makeLargestSpecialString(string s){
        int n=s.length();
        int count=0;int start=0;
        vector<string>childs;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                string subproblem=s.substr(start+1,i-start-1);
                string chunk='1'+makeLargestSpecialString(subproblem)+'0';
                childs.push_back(chunk);
                start=i+1;
            }
        }
        sort(childs.rbegin(),childs.rend());
        string ans="";
        for(auto &each:childs){
            ans+=each;
        }
        return ans;
    }
    string makeLargestSpecial(string s) {
        return makeLargestSpecialString(s);
    }
};