class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        int idx=-1;
        for(int i=str.length()-2;i>=0;i--){
              if(str[i]<str[i+1]){
                  idx=i;
                  break;
              }
        }
        if(idx==-1) return -1;
        int idx2=-1;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]>str[idx]){
                idx2=i;
                break;
            }
        }
        swap(str[idx],str[idx2]);
        sort(str.begin()+idx+1,str.end());
        long long int ans=stol(str);
        if(ans>INT_MAX)
        return -1;
        return ans;
    }
};