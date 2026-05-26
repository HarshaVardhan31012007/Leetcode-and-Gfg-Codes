class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr[26]={0};
        int brr[26]={0};
        int c=0;
        for(auto &each:word){
            int idx;
            if(isupper(each)){
               idx=each-'A';
               if(arr[idx]==0)
               arr[idx]++;
            }
            else{
               idx=each-'a';
               if(brr[idx]==0)
               brr[idx]++;
            }
            if(arr[idx]+brr[idx]==2){
               c++;
               brr[idx]++;
            }
        }
        return c;
    }
};