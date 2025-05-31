class Solution {
public:
    string reorganizeString(string s) {
      //method 1
    //   int arr[26]={0};
    //   for(int i=0;i<s.length();i++)
    //   arr[s[i]-'a']++;
    //   priority_queue<pair<int,char>>pq;
    //   for(int i=0;i<26;i++){
    //       if(arr[i]!=0)
    //       pq.push({arr[i],i+'a'});
    //   }
    //   int n=pq.size();int idx=0;
    //   while(!pq.empty()){
    //      auto top=pq.top();
    //      pq.pop();
    //      if(pq.size()==n-1){
    //        while(idx<s.length()&&top.first--){
    //         s[idx]=top.second;
    //         idx+=2;
    //        }
    //        if(top.first>0)
    //        return "";
    //      }
    //      else{
    //         while(top.first--){
    //             idx=idx>=s.length()?1:idx;
    //             s[idx]=top.second;
    //             idx+=2;
    //         }
    //      }
    //   }
    //        return s;



      int arr[26]={0};
      for(int i=0;i<s.length();i++)
      arr[s[i]-'a']++;
      int maxi=INT_MIN;char ch=0;
      for(int i=0;i<26;i++){
       if(arr[i]>maxi){
        maxi=arr[i];
        ch=i+'a';
       }
      }
    
      //lets place first character
      int idx=0;
      while(idx<s.length()&&maxi--){
        s[idx]=ch;
        idx+=2;
        arr[ch-'a']--;
      }
      if(maxi>0) return "";

      //lets palce remaining chracters
      for(int i=0;i<26;i++){
        while(arr[i]>0){
            idx=idx>=s.length()?1:idx;
            s[idx]=i+'a';
            idx+=2;
            arr[i]--;
        }
      }
        return s;
    } 
};