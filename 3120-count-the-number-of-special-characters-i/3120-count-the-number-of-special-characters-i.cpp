class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr[26]={0};
        int c=0;
        for(auto &each:word){
            int idx;
            if(isupper(each)){
               idx=each-'A';
               if(arr[idx]==-1||arr[idx]==0)
               arr[idx]++;
               if(arr[idx]==0){
                  c++;
                  arr[idx]=50;
               }
            }
            else{
               idx=each-'a';
               if(arr[idx]==1||arr[idx]==0)
               arr[idx]--;
               if(arr[idx]==0){
                  c++;
                  arr[idx]=50;
               }
            }
        }
        return c;
    }
};