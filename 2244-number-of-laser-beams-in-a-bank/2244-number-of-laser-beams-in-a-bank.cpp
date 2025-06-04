class Solution {
public:
    // bool check(string &k){
    //     for(int i=0;i<k.length();i++){
    //         if(k[i]=='1')
    //         return true;
    //     }
    //     return false;
    // }
    // int find(string &p){
    //     int count=0;
    //     for(int i=0;i<p.length();i++){
    //         if(p[i]=='1')
    //         count++;
    //     }
    //     return count;
    // }
    // int numberOfBeams(vector<string>& bank) {
    //     int count=0;
    //     int i=0;int j=1;
    //     while(j<bank.size()){
    //         bool a=check(bank[i]);
    //         bool b=check(bank[j]);
    //         if(a&&b){
    //            count+=find(bank[i])*find(bank[j]);
    //            i=j;
    //            j++;
    //         }
    //         else if(!a&&!b){
    //             i=j+1;
    //             j=j+2;
    //         }
    //         else if(!a){
    //             i++;
    //             if(i==j) j++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }
    //     return count;
    // }
    



    int number(string &k){
        int count=0;
        for(auto &each:k)
        count+=each-'0';
        // for(auto &each:k){
        //     if(each=='1')
        //     count++;
        // }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
       vector<int>devices;
       for(int i=0;i<bank.size();i++)
       devices.push_back(number(bank[i]));
       int i=0;int j=1;
       int ans=0;
       while(j<devices.size()){
          if(devices[i]&&devices[j]){
              ans+=devices[i]*devices[j];
              i=j;
              j++;
          }
          else if(!devices[i]&&!devices[j]){
            i=j+1;
            j=j+2;
          }
          else if(!devices[i]){
              i++;
              if(i==j) j++;
          }
          else
          j++;
       }
       return ans;
    }
};