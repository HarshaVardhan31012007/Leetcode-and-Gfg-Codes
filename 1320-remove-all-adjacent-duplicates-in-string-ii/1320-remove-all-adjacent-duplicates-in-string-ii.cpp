class Solution {
public:
    bool lastsame(string &ans, char&newch,int k){
        int it=ans.size()-1;
        for(int i=0;i<k-1;i++){
          if(ans[it]!=newch)
          return false;
          it--;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        
        //time limited exceeded
        // string ans="";
        // int n=s.length();
        // int i,j;
        // for(i=0;i<n;i++){
        //     char c=s[i];
        //     ans.push_back(c);
        //     cout<<ans<<endl;
        //     int  count=0;
        //   for( j=ans.length()-k;j<ans.length()&&ans.length()>=k;j++){
        //        if(ans[j]==ans[j+1])
        //         count++;
        //         cout<<count<<endl;
        //   }
        //   cout<<ans<<endl;
        //   int i=k;
        //   while(i--&&count==k-1){
        //     cout<<count<<endl;
        //      ans.pop_back();
        //   }
        //   cout<<ans<<endl;
        // }
        // return ans;
       

       //m1
       string ans="";
       int n=s.size();
       for(int i=0;i<n;i++){
        char newch=s[i];
        if(ans.size()<k-1)
        ans.push_back(newch);
        else{
            if(lastsame(ans,newch,k)){
                for(int i=0;i<k-1;i++)
                ans.pop_back();
            }
            else
            ans.push_back(newch);
        }
       }
        return ans;
    }
};