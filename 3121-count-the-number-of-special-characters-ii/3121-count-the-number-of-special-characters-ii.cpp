class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr[26]={0};
        int c=0;
        for(auto &each:word){
            int idx;
            if(isupper(each)){
               idx=each-'A';
               if(arr[idx]>=1){
                  c++;
                  arr[idx]=INT_MIN;
               }
               else if(arr[idx]==0){
                  arr[idx]=INT_MIN+1;
               }
            }
            else{
               idx=each-'a';
               if(arr[idx]>=0)
               arr[idx]++;
               else if(arr[idx]==INT_MIN){
                   c--;
                   arr[idx]++;
               }
            }
        }
        return c;
    }
};