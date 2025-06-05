class Solution {
public:
    // bool lastsame(string &ans, char&newch,int k){
    //     int it=ans.size()-1;
    //     for(int i=0;i<k-1;i++){
    //       if(ans[it]!=newch)
    //       return false;
    //       it--;
    //     }
      //  return true;
    //}
    string removeDuplicates(string s, int k) {
        
       //m1
    //    string ans="";
    //    int n=s.size();
    //    for(int i=0;i<n;i++){
    //     char newch=s[i];
    //     if(ans.size()<k-1)
    //     ans.push_back(newch);
    //     else{
    //         if(lastsame(ans,newch,k)){
    //             for(int i=0;i<k-1;i++)
    //             ans.pop_back();
    //         }
    //         else
    //         ans.push_back(newch);
    //     }
    //    }
    //     return ans;


    //m2
    // int i=0,j=0;
    // int n=s.size();
    // vector<int>count(n);
    // while(j<s.size()){
    //     s[i]=s[j];
    //     count[i]=1;
    //     if(i>0&&s[i]==s[i-1])
    //     count[i]+=count[i-1];
    //     if(count[i]==k)
    //     i=i-k;
    //     i++;
    //     j++;

    // }
    // return s.substr(0,i);

    
    vector<int>count(s.length(),0);
    int i=0;
    for(int j=0;j<s.length();i++,j++){
        s[i]=s[j];
        count[i]=1;
        if(i>0&&s[i]==s[i-1])
        count[i]+=count[i-1];
        if(count[i]==k)
        i=i-k;
    }
         return s.substr(0,i);
    }
};