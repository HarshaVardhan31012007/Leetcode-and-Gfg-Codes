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



    // string to_binary(int n){
    //     string temp="";
    //     while(n){
    //         int digit=(n&1);//n%2;
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
    //      vector<long long>palindromes;
    //      for(int i=1;i<=5000;i++){//may more than 5000 because ans of 5000 may lie on right side of 5000 but it is on left
    //           if(ispalindrome(i))
    //           palindromes.push_back(i);
    //      }
    //      vector<int>ans;
    //      for(auto &each:nums){
    //         long long mini=1e9;
    //          for(auto &p:palindromes){
    //               mini=min(mini,abs(p-each));
    //          }
    //          ans.push_back((int)mini);
    //      }
    //      return ans;
    // }



    //   string to_binary(int n){
    //     string temp="";
    //     while(n){
    //         int digit=(n&1);//n%2;
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
    //      vector<int>palindromes;
    //      for(int i=1;i<=5000;i++){//may more than 5000 because ans of 5000 may lie on right side of 5000 but it is on left
    //           if(ispalindrome(i))
    //           palindromes.push_back(i);
    //      }
    //      vector<int>ans;
    //      for(auto &each:nums){
    //         auto it=lower_bound(palindromes.begin(),palindromes.end(),(long long)each);
    //         if(*it==each) ans.push_back(0);
    //         else{
    //         int mini=1e9;
    //         if(it!=palindromes.end()) mini=min(mini,abs(*it-each));
    //         if(it!=palindromes.begin()){
    //           it--;
    //           mini=min(mini,abs(*it-each));
    //         }
    //         ans.push_back(mini);
    //         }
    //      }
    //      return ans;




    string to_binary(int n){
        string temp="";
        while(n){
            int digit=n%2;
            temp+=(digit==1?'1':'0');
            n=n/2;
        }
        return temp;
    }
    void solve(string &str,long long s,long long e,long long cans,long long &mini){
        if(s>e){
            mini=min(mini,abs(cans));
            return;
        }
        if(s==e){
            //odd number of digits//for one digit 1 to 0 and 0 to 1
            long long curr=(1LL<<s)*(str[s]-'0');
            long long bzero=curr;
            long long bone=(1LL<<s)-curr; 
            mini=min(mini,abs(cans-bzero));
            mini=min(mini,abs(cans+bone));
            return;
        }
        //this is not correct because sometimes 00 to 11 and 11 to 00
        // if(str[s]=='0'&&str[e]=='0'||str[s]=='1'&&str[e]=='1'){
        //     solve(str,s+1,e-1,cans,mini);
        //     return;
        // }
        long long curr=(1LL<<s)*(str[s]-'0')+(1LL<<e)*(str[e]-'0');
        long long bzero=curr;
        long long bone=(1LL<<s)+(1LL<<e)-curr;     
        solve(str,s+1,e-1,cans-bzero,mini);
        solve(str,s+1,e-1,cans+bone,mini);
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            string str=to_binary(nums[i]);
            long long s=0;
            long long e=str.length()-1;
            long long cans=0;
            long long mini=LLONG_MAX;
            solve(str,s,e,cans,mini);
            ans.push_back((int)mini);
        }
        return ans;
    }

};