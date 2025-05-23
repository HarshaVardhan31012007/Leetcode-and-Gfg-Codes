// User function Template for C++

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
      if(N<M) return -1;
       int sunday=S/7;
       int food=0;
       int it=0;
       for(int i=1;i<=S;i++){
           if(i%7!=0){
               if(food>=M*(sunday+1))
               food-=M;
               else{
                   food+=N-M;
                   it++;
               }
           }
           else{
               if(food>=M){
               food-=M;
               sunday--;
               }
               else
               return -1;
           }
       }
       return it;
    }
};