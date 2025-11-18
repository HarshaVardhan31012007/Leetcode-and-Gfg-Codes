class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
           int i=0;
           while(i<(int)bits.size()-1){
              if(bits[i]==0){
                i++;
              }
              else{
                i=i+2;
              }
           }
           if(i==bits.size()) return false;
           return true;
    }
};