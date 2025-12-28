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


       long long num=1;
       long long len=1;
       vector<long long>visited(k,0);
       while(1){
           if(visited[num]==1) return -1;
           if(!(num)) return len;
           visited[num]=1;
           num=(num*10LL+1LL)%k;
           len++;
       }
        return -1;
    }
};