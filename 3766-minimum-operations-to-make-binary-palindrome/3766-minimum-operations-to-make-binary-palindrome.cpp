class Solution {
public:
    // string to_binary(int n){
    //     string temp="";
    //     while(n){
    //         int digit=(n&1)//n%2;
    //         temp+=(digit==1?'1':'0');
    //         n=n/2;
    //     }
    //     return temp;
    // }
    // bool ispalindrome(int n){
    //     string temp=to_binary(n);
    //     int i=0;
    //     int j=temp.length()-1;
    //     while(i<j){
    //         if(temp[i]==temp[j]){
    //             i++;
    //             j--;
    //         }
    //         else
    //         return false;
    //     }
    //     return true;
    // }
    // vector<int> minOperations(vector<int>& nums) {
    //     vector<int>ans;
    //     for(int i=0;i<nums.size();i++){
    //        int n=nums[i];
    //        int n1=nums[i];
    //        while(1){
    //           if(ispalindrome(n)) {ans.push_back(n-nums[i]);break;}
    //           if(ispalindrome(n1)){ans.push_back(nums[i]-n1);break;}
    //           n++;
    //           n1--;
    //        }
    //     }
    //     return ans;
    // }



    string to_binary(int n){
        string temp="";
        while(n){
            int digit=(n&1);//n%2;
            temp+=(digit==1?'1':'0');
            n=n/2;
        }
        return temp;
    }
    bool ispalindrome(int n){
        string temp=to_binary(n);
        int i=0;
        int j=temp.length()-1;
        while(i<j){
            if(temp[i]==temp[j]){
                i++;
                j--;
            }
            else
            return false;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
         vector<long long>palindromes;
         for(int i=1;i<=5000;i++){//may more than 5000 because ans of 5000 may lie on right side of 5000 but it is on left
              if(ispalindrome(i))
              palindromes.push_back(i);
         }
         vector<int>ans;
         for(auto &each:nums){
            long long mini=1e9;
             for(auto &p:palindromes){
                  mini=min(mini,abs(p-each));
             }
             ans.push_back((int)mini);
         }
         return ans;
    }
};