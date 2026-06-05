class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(),s.end(),[&](char &a,char &b){
            int idx1=order.find(a);
            int idx2=order.find(b);
            return idx1<idx2;
        });
        return s;
    }
};