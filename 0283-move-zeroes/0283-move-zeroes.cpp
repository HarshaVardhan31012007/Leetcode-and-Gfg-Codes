class Solution {
public:
    void moveZeroes(vector<int>& s) {
        int n=s.size();
        int i=0;
        int j=0;
        while(j<n){
            while(j<n&&s[j]==0) j++;
            while(i<n&&s[i]!=0) i++;
            if(i<n&&j<n&&i<j){
              s[i]=s[j];
              s[j]=0;
              i++;j++;
            }
            else if(i<n&&j<n&&i>=j){
               j=i+1;
            }
            else
            break;
        }
    }
};