class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int basket1=-1;int basket2=-1;
        // int c1=0;int c2=0;
        // int n=fruits.size();
        // int i=0;
        // int j=0;
        // int ans=0;
        // while(j<n){
        //     if(fruits[j]==basket1){
        //         c1++;
        //     }
        //     else if(fruits[j]==basket2){
        //         c2++;
        //     }
        //     else{
        //         while(c1!=0&&c2!=0){
        //             if(fruits[i]==basket1) c1--;
        //             else if(fruits[i]==basket2) c2--;
        //             i++;
        //         }
        //         if(c1==0){
        //             basket1=fruits[j];
        //             c1=1;
        //         }
        //         else if(c2==0){
        //             basket2=fruits[j];
        //             c2=1;
        //         }
        //     }
        //     ans=max(ans,c1+c2);
        //     j++;
        // }
        // return ans;



        // int basket1=-1;int basket2=-1;
        // int c1=0;int c2=0;
        // int lastpos1=-1;int lastpos2=-1;
        // int n=fruits.size();
        // int i=0;
        // int j=0;
        // int ans=0;
        // unordered_map<int,unordered_map<int,int>>freq;
        // while(j<n){
        //     freq[j][basket1]=c1;
        //     freq[j][basket2]=c2;
        //     if(fruits[j]==basket1){
        //         c1++;
        //         lastpos1=j;
        //     }
        //     else if(fruits[j]==basket2){
        //         c2++;
        //         lastpos2=j;
        //     }
        //     else{
        //         if(lastpos1==-1){
        //             basket1=fruits[j];
        //             c1=1;
        //             lastpos1=j;
        //         }
        //         else if(lastpos2==-1){
        //             basket2=fruits[j];
        //             c2=1;
        //             lastpos2=j;
        //         }
        //         else if(lastpos1<lastpos2){
        //             i=lastpos1+1;
        //             basket1=fruits[j];
        //             c1=1;
        //             c2-=freq[i][basket2];
        //             lastpos1=j;
        //         }
        //         else{
        //             i=lastpos2+1;
        //             basket2=fruits[j];
        //             c2=1;
        //             c1-=freq[i][basket1];
        //             lastpos2=j;
        //         }
        //     }
        //     ans=max(ans,c1+c2);
        //     j++;
        // }
        // return ans;





    //    unordered_map<int,int>freq;
    //    int i=0;
    //    int j=0;
    //    int n=fruits.size();
    //    int ans=0;
    //    while(j<n){
    //       freq[fruits[j]]++;
    //       while(freq.size()>2){
    //          freq[fruits[i]]--;
    //          if(freq[fruits[i]]==0) freq.erase(fruits[i]);
    //          i++;
    //       } 
    //       int c=0;
    //       for(auto &each:freq)
    //       c+=each.second;
    //       ans=max(ans,c);
    //       j++;
    //    }
    //    return ans;



    unordered_map<int,int>freq;
       int i=0;
       int j=0;
       int n=fruits.size();int c=0;
       int ans=0;
       while(j<n){
          freq[fruits[j]]++;
          c++;
          if(freq.size()>2){
             freq[fruits[i]]--;
             c--;
             if(freq[fruits[i]]==0) freq.erase(fruits[i]);
             i++;
          } 
          if(freq.size()<=2)
          ans=max(ans,c);
          j++;
       }
       return ans;
    }
};