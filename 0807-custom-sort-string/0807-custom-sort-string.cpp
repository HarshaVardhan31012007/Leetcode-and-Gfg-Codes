// string str;
// class Solution {
// public:
//     static bool comp(char &first,char &second){
//       return str.find(first)<str.find(second);
//     }
//     string customSortString(string order, string s) {
//         str=order;
//         sort(s.begin(),s.end(),comp);
//         return s;
//     }
// };

class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(),s.end(),[order](char &a,char &b){
            cout<<a<<" "<<b<<endl;
            return order.find(a)<order.find(b);
        });
        return s;
    }
};

