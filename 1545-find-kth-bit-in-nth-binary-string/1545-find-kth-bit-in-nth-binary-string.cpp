class Solution {
public:
    // vector<int>len;
    // char findKthBitHelper(int n,int k){
    //     if(n==1) return '0';
    //     int currlen=len[n];
    //     int prevlen=len[n-1];
    //     if(k==(currlen/2+1)) return '1';
    //     if(k<=(currlen/2)){
    //         return findKthBitHelper(n-1,k);
    //     }
    //     else{
    //         int pos=k-(currlen/2+1);
    //         return '1'+'0'-findKthBitHelper(n-1,prevlen-pos+1);
    //     }
    // }
    // char findKthBit(int n, int k) {
    //     len.assign(21,0);
    //     len[1]=1;
    //     for(int i=2;i<=20;i++){
    //         len[i]=(len[i-1]*2)+1;
    //     }
    //     return findKthBitHelper(n,k);
    // }



    
    char findKthBitHelper(int n,int k){
        if(n==1) return '0';
        int currlen=(1<<n)-1;
        if(k==(currlen/2+1)) return '1';
        if(k<=(currlen/2)){
            return findKthBitHelper(n-1,k);
        }
        else{
            return '1'+'0'-findKthBitHelper(n-1,currlen-(k-1));
        }
    }
    char findKthBit(int n, int k) {
        return findKthBitHelper(n,k);
    }
};