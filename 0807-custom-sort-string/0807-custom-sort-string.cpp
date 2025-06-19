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
    string str;

    bool comp(char first, char second) {
        return str.find(first) < str.find(second);
    }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), [this](char a, char b) {
            return comp(a, b);
        });
        return s;
    }
};
