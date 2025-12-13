class Solution {
public:
    class Coupon{
        public:
        string business;
        string code;
    };
    bool check(string s){
        return s=="electronics"||s=="grocery"||s=="pharmacy"||s=="restaurant";
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<Coupon>temp;
        for(int i=0;i<n;i++){
            if(!isActive[i]) continue;
            if(!code[i].empty()&&check(businessLine[i])){
                bool flag=1;
                for(auto &each:code[i]){
                    if(!(isdigit(each)||isalpha(each)||each=='_')){
                      flag=0;break;
                    }
                }
                if(flag)
                temp.push_back({businessLine[i],code[i]});
            }
        }
        sort(temp.begin(),temp.end(),[&](Coupon &a,Coupon &b){
            if(a.business!=b.business) return a.business<b.business;
            return a.code<b.code;
        });
        vector<string>ans;
        for(auto &each:temp){
            ans.push_back(each.code);
        }
        return ans;
    }
};