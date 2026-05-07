class Solution {
public:
    // void solve(int i,int n,unordered_set<int>&st,vector<int>&ans,vector<int>&temp){
    //     if(i>n){
    //        int x=temp.back();
    //        if((x&(x-1))==0) ans=temp;
    //        return;
    //     }
    //     for(int j=1;j<=n;j++){
    //         if(st.count(j)) continue;
    //         int x=(temp.back()^j);
    //         if((x&(x-1))==0){
    //             temp.push_back(j);
    //             st.insert(j);
    //             solve(i+1,n,st,ans,temp);
    //             if(!ans.empty()) return;
    //             temp.pop_back();
    //             st.erase(j);
    //         }
    //     }
    // }


    // vector<string>helper(int n){
    //     if(n==1){
    //         return {"0","1"};
    //     }
    //     vector<string>temp=helper(n-1);
    //     vector<string>ans;
    //     for(int i=0;i<temp.size();i++){
    //         ans.push_back(temp[i]+"0");
    //     }
    //     for(int i=temp.size()-1;i>=0;i--){
    //         ans.push_back(temp[i]+"1");
    //     }
    //     return ans;
    // }
    // vector<int> grayCode(int n) {
    //     // vector<int>ans;
    //     // vector<int>temp;
    //     // temp.push_back(0);
    //     // unordered_set<int>st;
    //     // n=((1<<n)-1);
    //     // solve(1,n,st,ans,temp);
    //     // return temp;


    //     // vector<int>ans;
    //     // for(int i=0;i<(1<<n);i++){
    //     //     ans.push_back(i^(i>>1));
    //     // }
    //     // return ans;


    //     vector<string>result=helper(n);
    //     vector<int>ans;
    //     for(auto &each:result){
    //         bitset<32>bt(each);
    //         ans.push_back(bt.to_ulong());
    //     }
    //     return ans;
    // }



    vector<int>helper(int n){
        if(n==1){
            return {0,1};
        }
        vector<int>temp=helper(n-1);
        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]*2);
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]*2+1);
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        // vector<int>ans;
        // vector<int>temp;
        // temp.push_back(0);
        // unordered_set<int>st;
        // n=((1<<n)-1);
        // solve(1,n,st,ans,temp);
        // return temp;


        // vector<int>ans;
        // for(int i=0;i<(1<<n);i++){
        //     ans.push_back(i^(i>>1));
        // }
        // return ans;


    
        vector<int>ans=helper(n);
        return ans;
    }
};