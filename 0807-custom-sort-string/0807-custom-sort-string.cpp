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

// class Solution {
// public:
//     string customSortString(string order, string s) {
//         sort(s.begin(),s.end(),[order](char &a,char &b){
//             return order.find(a)<order.find(b);
//         });
//         return s;
//     }
// };

// class Solution {
// public:
//     string customSortString(string order, string s) {
//         int arr[26]={0};
//         for(int i=0;i<order.size();i++){
//             arr[order[i]-'a']=i+1;
//         }
//         sort(s.begin(),s.end(),[arr](char &a,char &b){
//             return arr[a-'a'] < arr[b-'a'];
//         });
//         return s;
//     }
// };


class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<order.size();i++){
            mpp[order[i]]=i+1;
        }
        sort(s.begin(),s.end(),[&mpp](char &a,char &b){
            return mpp[a] < mpp[b];
        });
        return s;
    }
};