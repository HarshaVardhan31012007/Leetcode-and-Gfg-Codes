// class Solution {
// public:
//     unordered_set<int>st;
//     int N;
//     Solution(int n, vector<int>& blacklist) {
//         for(auto &each:blacklist){
//             st.insert(each);
//         }
//         N=n;
//     }
    
//     int pick() {
//         int r=rand()%N;
//         while(st.count(r)){
//             r=rand()%N;
//         }
//         return r;
//     }
// };

// /**
//  * Your Solution object will be instantiated and called as such:
//  * Solution* obj = new Solution(n, blacklist);
//  * int param_1 = obj->pick();
//  */



class Solution {
public:
    unordered_map<int,int>mpp;
    int M;
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int>st(blacklist.begin(),blacklist.end());
        int last=n-1;
        M=n-blacklist.size();
        for(auto &each:blacklist){
            if(each<M){
                while(st.count(last)) last--;
                mpp[each]=last--;
            }
        }
    }
    
    int pick() {
        int r=rand()%M;
        if(mpp.count(r)) return mpp[r];
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */