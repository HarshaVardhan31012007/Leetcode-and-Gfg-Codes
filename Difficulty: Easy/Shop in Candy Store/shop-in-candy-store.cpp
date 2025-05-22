class Solution {
  public:
    vector<int> candyStore(int candies[], int N, int p) {
        // vector<int>arr;
        // for(int i=0;i<N;i++)
        // arr.push_back(candies[i]);
        // sort(arr.begin(),arr.end());
        // int ans1=0;
        // int K=p;
        // for(int i=0;i<arr.size();i++){
        //     ans1+=arr[i];
        //     while(K--&&arr.size()>i+1)
        //     arr.pop_back();
        //     K=p;
        // }
        // vector<int>brr;
        // for(int i=0;i<N;i++)
        // brr.push_back(candies[i]);
        // sort(brr.rbegin(),brr.rend());
        // int ans2=0;
        // K=p;
        // for(int i=0;i<brr.size();i++){
        //     ans2+=brr[i];
        //     while(K--&&brr.size()>i+1)
        //     brr.pop_back();
        //     K=p;
        // }
        // return {ans1,ans2};
        
        
        
        //Two pointer approach
        int K=p;
        sort(candies,candies+N);
        int buy=0;
        int free=N-1;
        int ans1=0;
        while(buy<=free){
            ans1+=candies[buy];
            buy++;
            free=free-K;
        }
        buy=N-1;
        free=0;
        int ans2=0;
        while(free<=buy){
            ans2+=candies[buy];
            buy--;
            free=free+K;
        }
        return {ans1,ans2};
    }
};