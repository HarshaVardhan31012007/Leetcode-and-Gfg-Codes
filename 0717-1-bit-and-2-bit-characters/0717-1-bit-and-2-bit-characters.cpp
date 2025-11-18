class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //    int i=0;
        //    while(i<(int)bits.size()-1){
        //       if(bits[i]==0){
        //         i++;
        //       }
        //       else{
        //         i=i+2;
        //       }
        //    }
        //    if(i==bits.size()) return false;
        //    return true;


        if(bits.size()==1) return true;
        if(bits[bits.size()-2]==0) return true;
        int i=bits.size()-2;
        while(i>=0){
            if(bits[i]==0) break;
            i--;
        }
        int len=bits.size()-i-2;
        if(len&1) return false;
        return true;
    }
};