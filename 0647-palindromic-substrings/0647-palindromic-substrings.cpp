class Solution {
public:
int findcount(string &ans,int i,int j){
    int count=0;
    while(i>=0&&j<ans.size()&&ans[i]==ans[j]){
        count++;
        i--;
        j++;
    }
    return count;
}
    int countSubstrings(string s) {
        
int tcount=0;
for(int center=0;center<s.size();center++){
    int i=center;
    int j=center;
    int ocount=findcount(s,i,j);
     i=center;
     j=center+1;
    int ecount=findcount(s,i,j);
    tcount=tcount+ecount+ocount;
}
return tcount;
    }
};