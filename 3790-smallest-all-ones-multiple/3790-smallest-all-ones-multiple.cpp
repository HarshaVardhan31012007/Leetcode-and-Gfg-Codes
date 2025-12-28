class Solution {
public:
    int minAllOneMultiple(int k) {
    //    long long num=1;
    //     long long len=1;
    //     unordered_map<int,bool>visited;
    //    while(1){
    //        if(visited[num]==1) return -1;
    //        if(!(num)) return len;
    //        visited[num]=1;
    //        num=(num*10LL+1LL)%k;
    //        len++;
    //    }
    //     return -1;


    //    long long num=1;
    //    long long len=1;
    //    vector<long long>visited(k,0);
    //    while(1){
    //        if(visited[num]==1) return -1;
    //        if(!(num)) return len;
    //        visited[num]=1;
    //        num=(num*10LL+1LL)%k;
    //        len++;
    //    }
    //     return -1;



       long long num=1;
       if(k%5==0||k%2==0) return -1;
       for(int i=0;i<k;i++){
           if(!num) return i+1;
           num=(num*10+1)%k;
       }
       return -1;
    }
};