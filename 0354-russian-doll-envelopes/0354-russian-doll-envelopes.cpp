class Solution {
public:
    //DP 

    // bool issafe(vector<int>&c1,vector<int>&c2){
    //     if(c1[0]<c2[0] && c1[1]<c2[1])
    //     return true;
    //     else
    //     return false;
    // }
    // int solve(vector<vector<int>>& envelopes,int n){
    //     vector<int>cur(n+1,0);
    //     for(int curr=n-1;curr>=0;curr--){
    //             for(int prev=curr-1;prev>=-1;prev--){
    //             int l=0;
    //             if(prev==-1||issafe(envelopes[prev],envelopes[curr]))
    //             l=1+cur[curr+1];
    //             int r=cur[prev+1];
    //             cur[prev+1]=max(l,r);
    //         }
    //     }
    //     return cur[0];
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n=envelopes.size();
    //     sort(envelopes.begin(),envelopes.end());
    //     return solve(envelopes,n);
    // }


     static bool comp(vector<int> &a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(temp.back()<envelopes[i][1]){
                temp.push_back(envelopes[i][1]);
            }
            else{
                auto ind=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[ind]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};