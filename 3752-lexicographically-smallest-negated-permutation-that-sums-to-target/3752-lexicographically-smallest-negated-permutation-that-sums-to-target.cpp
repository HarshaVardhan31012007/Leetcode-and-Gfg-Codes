class Solution {
public:
    // bool compareb(vector<int>&ans,vector<int>&a){
    //     for(int i=0;i<ans.size();i++){
    //         if(ans[i]>a[i])
    //             return true;
    //         else if(ans[i]<a[i])
    //             return false;
    //     }
    //     return false;
    // }
    // void solve(int n,int i,long long target,int sum,vector<int>&temp,vector<int>&ans){
    //     if(i>n){
    //         if(sum==target){
    //             vector<int>a(temp);
    //             sort(a.begin(),a.end());
    //             if(ans.empty())
    //                 ans=a;
    //             else if(compareb(ans,a))
    //                 ans=a;
    //         }
    //         return;
    //     }
    //     temp.push_back(i);
    //     solve(n,i+1,target,sum+i,temp,ans);
    //     temp.pop_back();
    //     temp.push_back(-i);
    //     solve(n,i+1,target,sum-i,temp,ans);
    //     temp.pop_back();
    // }
    // vector<int> lexSmallestNegatedPerm(int n, long long target) {
    //      vector<int>temp;
    //      vector<int>ans;
    //      solve(n,1,target,0,temp,ans);
    //      return ans;
    // }



  
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S=1LL*n*(n+1)/2;
        if(target>S||target<-S||((S-target)&1)) return {};
        long long diff=(S-target)/2;//diff should be long long as target 10 power 10
        vector<int>ans;
        int last=INT_MAX;
        for(int i=n;i>=1;i--){
            if(diff>=i*1LL){// i also should be long long so that comparable
                ans.push_back(-i);
                diff-=i;
                if(diff==0){
                    last=i-1;
                    break;
                }
            }
            else{
                last=i;
                break;
            }
        }
        if(diff!=0)
        ans.push_back(-diff);
        for(int i=1;i<=last;i++){
            if(i!=diff)
                ans.push_back(i);
        }
        return ans;
    }
};