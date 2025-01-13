class Solution {
public:
 //method 1
//   int findmax(queue<int>q){
//      int maxAns=INT_MIN;
//      while(!q.empty()){
//         if(q.front()>maxAns){
//             maxAns=q.front();
//         }
//         q.pop();
//      }
//      return maxAns;
//   }
    
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
           //method 1
        // vector<int>ans;
        // queue<int>q;
        // //step1
        // //process first window
        // for(int i=0;i<k;i++){
        //     q.push(arr[i]);
        // }
        // //process for rem windows
        // for(int i=k;i<arr.size();i++){
        //     //ans ko process
        //     int Ans=findmax(q);
        //     ans.push_back(Ans);
        //     //removal
        //     q.pop();
        //     //add
        //     q.push(arr[i]);
        // }
        //  int Ans=findmax(q);
        // ans.push_back(Ans);
        // return ans;


        //method 2
        vector<int>ans;
        deque<int>q;
        int n=arr.size();
        //step1
        //process first window
        //store indices
        for(int i=0;i<k;i++){
            while(!q.empty()&&arr[q.back()]<arr[i]){
                cout<<q.back()<<endl;
            q.pop_back();
            }
            q.push_back(i);
        }
        
        //process for rem windows
        for(int i=k;i<n;i++){
             //ans store previous ka
           ans.push_back(arr[q.front()]);
            //removal
            if(i-q.front()>=k){
                q.pop_front();
            }
            //add
           while(!q.empty()&&arr[q.back()]<arr[i]){
            q.pop_back();
           }
           q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        return ans;
    }
};